import salome
homard=salome.lcc.FindOrLoadComponent("FactoryServer","HOMARD")
import os
home=os.environ["HOME"]
etape0= home+"essai/etape0"
archive=+"/archives"
FichierConfiguration=etape0+"HOMARD.Configuration.0.vers.1"
monCas=homard.CreateCas("MonCas",etape0)
print monCas
monCas.AjoutIter(1,FichierConfiguration)
print "ici"
monCas.CalculIter(1)
print "la"
