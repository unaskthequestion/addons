#include "crAnimalXMLManager.h"

crAnimalXMLManager::crAnimalXMLManager()
{

}

crAnimalXMLManager::~crAnimalXMLManager()
{
}

void crAnimalXMLManager::setup(ofxBox2d * _box2d, string _XMLfilename, int _vw, int _vh)
{   
	XMLfilename = _XMLfilename;
	crBase2dManager::setup(_box2d, _vw, _vh);
	bSkinOn = false;
}

bool crAnimalXMLManager::capture(ofImage *currImg, ofImage *bgImg)
{
	bool bCambiazo;

	crBaseManager::capture(currImg, bgImg);

	if(!bSkinOn && skins.size()>0)
	{
		bSkinOn = true;
		bCambiazo = false;
		cout << "AnimalXMLManager -> skins captured";
	}
	else
		bCambiazo = true;

	return bCambiazo;
}

void crAnimalXMLManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob )
{
	if(!bSkinOn)
	{
		// capturo els skins de les peces
		crSkin skin;
		skin.setup(_skin, rect);
		skins.push_back(skin);
	}
	else
	{
		// capturo nous bitxos i els passo l' array d' skins de peces
		crAnimal animal;
        animal.setup(box2d, XMLfilename, vw, vh);
		animal.setSkin(&skins);
		animal.born(rect);
		animals.push_back(animal);

	}
}

void crAnimalXMLManager::update()
{
        for (int i = 0; i < animals.size(); i++)
            animals[i].update();	
}

void crAnimalXMLManager::draw(bool bDrawlines, int offX)
{
        for (int i = 0; i < animals.size(); i++)
            animals[i].draw(bDrawlines, offX);	
}

void crAnimalXMLManager::clear()
{
//  for (int i = 0; i < animals.size(); i++)
//		animals[i].clear();
   animals.clear();
   skins.clear();
}

void crAnimalXMLManager::touch(int _x,int _y, int forceX, int forceY)
{
 //   for (int i = 0; i < animals.size(); i++)
//		animals[i].touch(_x, _y, forceX, forceY);
}

void crAnimalXMLManager::drag(int _x, int _y)
{
 //       for (int i = 0; i < animals.size(); i++)
 //           animals[i].drag(_x,_y);	
}
