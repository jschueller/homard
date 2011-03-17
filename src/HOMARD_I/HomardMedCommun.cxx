#include "HomardMedCommun.h"
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

extern "C" 
{
#include <med.h>
}

#include "utilities.h"
// =======================================================================
std::set<std::string> GetListeGroupesInMedFile(const char * aFile)
// =======================================================================
{
   std::set<std::string> ListeGroupes;
   int MedIdt = MEDouvrir(const_cast<char *>(aFile),MED_LECTURE);
   if ( MedIdt < 0 ) { return ListeGroupes; };

   char maa[MED_TAILLE_NOM+1];
   char desc[MED_TAILLE_DESC+1];
   char nomfam[MED_TAILLE_NOM+1];
   med_int numfam;

   med_int mdim;
   med_maillage type;
   med_int numMaillage=1;
   if ( MEDmaaInfo(MedIdt,numMaillage,maa,&mdim,&type,desc) < 0 ) { return ListeGroupes; };
   med_int nfam, ngro, natt;
   if ((nfam = MEDnFam(MedIdt,maa)) < 0) { return ListeGroupes; };
   for (int i=0;i<nfam;i++) 
   {
      if ((ngro = MEDnGroupe(MedIdt,maa,i+1)) < 0) 
      {
        // GERALD -- QMESSAGE BOX
        std::cerr << " Error : Families are unreadable" << std::endl;
        std::cerr << "Pb avec la famille : " << i << std::endl;
        break;
      }
      if (ngro == 0) continue;

      if ((natt = MEDnAttribut(MedIdt,maa,i+1)) < 0) 
      {
        // GERALD -- QMESSAGE BOX
        std::cerr << " Error : Families are unreadable" << std::endl;
        std::cerr << "Pb avec la famille : " << i << std::endl;
        break;
      }

      med_int* attide = (med_int*) malloc(sizeof(med_int)*natt);
      med_int* attval = (med_int*) malloc(sizeof(med_int)*natt);
      char*    attdes = (char *)   malloc(MED_TAILLE_DESC*natt+1);
      char*    gro    = (char*)    malloc(MED_TAILLE_LNOM*ngro+1);
      if (MEDfamInfo(MedIdt,maa,i+1,nomfam,&numfam,attide,attval,attdes,
                      &natt,gro,&ngro) < 0) 
      { 
        // GERALD -- QMESSAGE BOX
        std::cerr << " Error : Families are unreadable" << std::endl;
        std::cerr << "Pb avec la famille : " << i << std::endl;
         break;
      }
      free(attide);
      free(attval);
      free(attdes);
      if ((numfam )> 0) { continue;} // On ne garde que les familles d elts

      for (int j=0;j<ngro;j++) 
      {
           char str2[MED_TAILLE_LNOM+1];
           strncpy(str2,gro+j*MED_TAILLE_LNOM,MED_TAILLE_LNOM);
           str2[MED_TAILLE_LNOM] = '\0';
           ListeGroupes.insert(std::string(str2));

      }
      free(gro);
   }
   MEDfermer(MedIdt);
   return ListeGroupes;
}

// =======================================================================
std::vector<double> GetBoundingBoxInMedFile(const char * aFile)
// =======================================================================
{
// Le vecteur en retour contiendra les informations suivantes :
// en position 0 et 1 Xmin, Xmax et en position 2 Dx si < 0  2D
// en position 3 et 4 Ymin, Ymax et en position 5 Dy si < 0  2D
// en position 6 et 7 Zmin, Zmax et en position 8 Dz si < 0  2D
//  9 distance max dans le maillage

   std::vector<double> LesExtremes;
   
   				// Ouverture du Fichier Med
   int MedIdt = MEDouvrir(const_cast<char *>(aFile),MED_LECTURE);
   if (MedIdt <0) 
   {
          // GERALD -- QMESSAGE BOX
          std::cerr << "Error : mesh is unreadable" << std::endl;
          return LesExtremes;
   }

                                // Le fichier Med est lisible
				// Boucle sur les noms de maillage
   int numberOfMeshes = MEDnMaa(MedIdt) ;
   if (numberOfMeshes != 1 ) 
   {
          // GERALD -- QMESSAGE BOX
          std::cerr << "Error : file contains more than one mesh" << std::endl;
          return LesExtremes;
   }

   char maa[MED_TAILLE_NOM+1];
   char desc[MED_TAILLE_DESC+1];
   char nomcoo[3*MED_TAILLE_PNOM+1];
   char unicoo[3*MED_TAILLE_PNOM+1];
   med_maillage type;
   med_repere rep;
   med_booleen inonoe,inunoe;

   med_int dim;
   med_int numMaillage=1;

   if (MEDmaaInfo(MedIdt,numMaillage,maa,&dim,&type,desc) < 0) 
   {
          // GERALD -- QMESSAGE BOX
          std::cerr << "Error : mesh " << numMaillage << " is unreadable" << std::endl;
          return LesExtremes;
   }

   med_int nnoe  = MEDnEntMaa(MedIdt,maa,MED_COOR,MED_NOEUD,(med_geometrie_element)0,(med_connectivite)0);
   if ( nnoe < 0) 
   {
          // GERALD -- QMESSAGE BOX
          std::cerr << "Error : mesh " << numMaillage << " is unreadable" << std::endl;
          return LesExtremes;
   }

   med_float* coo    = (med_float*) malloc(sizeof(med_float)*nnoe*dim);
   med_int*   numnoe = (med_int*)   malloc(sizeof(med_int)*nnoe);
   med_int*   nufano = (med_int*)   malloc(sizeof(med_int)*nnoe);
   char *     nomnoe = (char*)      malloc(MED_TAILLE_PNOM*nnoe+1);

   MEDnoeudsLire(MedIdt,maa,dim,coo,MED_NO_INTERLACE,&rep,
                      nomcoo,unicoo,nomnoe,&inonoe,numnoe,&inunoe,
                      nufano,nnoe);

   med_float xmin,xmax,ymin,ymax,zmin,zmax;
   
   xmin=coo[0];
   xmax=coo[0];
   for (int i=1;i<nnoe;i++)
   {
      xmin = min(xmin,coo[i]);
      xmax = max(xmax,coo[i]);
   }
//
   if (dim > 1)
   {
       ymin=coo[nnoe]; ymax=coo[nnoe];
       for (int i=nnoe+1;i<2*nnoe;i++)
       {
           ymin = min(ymin,coo[i]);
           ymax = max(ymax,coo[i]);
       }
   }
   else
   {
       ymin=0;
       ymax=0;
       zmin=0;
       zmax=0;
   }
//
   if (dim > 2)
   {
       zmin=coo[2*nnoe]; zmax=coo[2*nnoe];
       for (int i=2*nnoe+1;i<3*nnoe;i++)
       {
           zmin = min(zmin,coo[i]);
           zmax = max(zmax,coo[i]);
       }
   }
   else
   {
       zmin=0;
       zmax=0;
   }
   MEDfermer(MedIdt);

   MESSAGE( "_______________________________________");
   MESSAGE( "xmin : " << xmin << " xmax : " << xmax );
   MESSAGE( "ymin : " << ymin << " ymax : " << ymax );
   MESSAGE( "zmin : " << zmin << " zmax : " << zmax );
   MESSAGE( "_______________________________________" );
   double epsilon = 1.e-6 ;
   LesExtremes.push_back(xmin);
   LesExtremes.push_back(xmax);
   LesExtremes.push_back(0);
   LesExtremes.push_back(ymin);
   LesExtremes.push_back(ymax);
   LesExtremes.push_back(0);
   LesExtremes.push_back(zmin);
   LesExtremes.push_back(zmax);
   LesExtremes.push_back(0);


   double max1=max ( LesExtremes[1] - LesExtremes[0] , LesExtremes[4] - LesExtremes[3] ) ;
   double max2=max ( max1 , LesExtremes[7] - LesExtremes[6] ) ;
   LesExtremes.push_back(max2);

// LesExtremes[0] = Xmini du maillage
// LesExtremes[1] = Xmaxi du maillage
// LesExtremes[2] = increment de progression en X
// LesExtremes[3,4,5] : idem pour Y
// LesExtremes[6,7,8] : idem pour Z
// LesExtremes[9] = ecart maximal entre coordonnees
// On fait un traitement pour dans le cas d'une coordonnee constante
// inhiber ce cas en mettant un increment negatif
//
   double diff = LesExtremes[1] - LesExtremes[0];
   if (fabs(diff)  > epsilon*max2)
   {
      LesExtremes[2] = diff/100.;
   }
   else
   {
      LesExtremes[2] = -1. ;
   }

   diff = LesExtremes[4] - LesExtremes[3];
   if (fabs(diff)  > epsilon*max2)
   {
      LesExtremes[5]=diff/100.;
   }
   else
   {
      LesExtremes[5] = -1. ;
   }

   diff = LesExtremes[7] - LesExtremes[6];
   if (fabs(diff)  > epsilon*max2)
   {
      LesExtremes[8]=diff/100.;
   }
   else
   {
      LesExtremes[8] = -1. ;
   }

   MESSAGE ( "_______________________________________" );
   MESSAGE ( "xmin : " << LesExtremes[0] << " xmax : " << LesExtremes[1] << " xincr : " << LesExtremes[2] );
   MESSAGE ( "ymin : " << LesExtremes[3] << " ymax : " << LesExtremes[4] << " yincr : " << LesExtremes[5] );
   MESSAGE ( "zmin : " << LesExtremes[6] << " zmax : " << LesExtremes[7] << " zincr : " << LesExtremes[8] );
   MESSAGE ( "dmax : " << LesExtremes[9] );
   MESSAGE ( "_______________________________________" );

   return  LesExtremes;
}

