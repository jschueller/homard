//
//  File   : HomardConfigFile.hxx
//  Author : Paul RASCLE, EDF
//  Module : SMESH


#ifndef _HOMARD_CONFIG_FILE
#define _HOMARD_CONFIG_FILE

#include <string>
#include <map>
#include <list>

using namespace std;

class HomardConfigFile
{
	typedef string motcle;
	typedef string valeur;

public  :
	HomardConfigFile();
	~HomardConfigFile();
         bool initVal(const string motclef ,const string valeur);
         bool createFile();
         void setBilan(bool etat);
         string getMyDir();

protected :

	std::list<motcle> _motscle_ss_valeur;
	std::list<motcle> _motscle_oui_non ;
	std::list<motcle> _motscle_autre;

	std::map <motcle,valeur> _dictValeur;
	std::map <motcle,int>    _dictValeuroui;

        string _nomFichier;
        string _prefix;
        bool   _bBilan;
        string _myDir;

        bool cherche_dans_liste(std::list<motcle> & liste , const motcle motclef);
} ;
#endif 
