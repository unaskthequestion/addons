#include "wuAnimalXMLManager.h"

wuAnimalXMLManager::wuAnimalXMLManager()
{

}

wuAnimalXMLManager::~wuAnimalXMLManager()
{
}

void wuAnimalXMLManager::setup(ofxBox2d * _box2d, string _XMLfilename, int _vw, int _vh)
{   
	XMLfilename = _XMLfilename;
	wuBase2dManager::setup(_box2d, _vw, _vh);
	bSkinOn = false;
	bGo = false;
	bReadyGo = false;
}

bool wuAnimalXMLManager::capture(ofImage *currImg, ofImage *bgImg)
{
	bool bCambiazo;

	if(bReadyGo)
	{
		// capturo nous bitxos i els passo l' array d' skins de peces
//		wuAnimal animal;
        animal.setup(box2d, XMLfilename, vw, vh, &skins, rectInit);
//		animals.push_back(animal);
		bCambiazo = false;
		bGo = true;
	}else
	{
		wuBaseManager::capture(currImg, bgImg);

		if(!bSkinOn && skins.size()>0)
		{
			OrderSkins();
			bSkinOn = true;
			bCambiazo = false;
			cout << "AnimalXMLManager -> skins captured";
			// a partir d' ara nom�s m' interessa el blob del bitxo muntat
			setMaxBlobs(1);
		}
		else if(bSkinOn && !bReadyGo && skins.size()>0)
		{
			bCambiazo = true;
			bReadyGo = true;
		}
	}

	return bCambiazo;
}

void wuAnimalXMLManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob )
{
	if(!bSkinOn)
	{
		// capturo els skins de les peces
		wuSkin skin;
		skin.setup(_skin, rect);
		skins.push_back(skin);
	}
	else if(!bReadyGo)
	{
		skinInit.setup(_skin, rect);
		rectInit = rect;
	}
}

void wuAnimalXMLManager::update()
{
//        for (int i = 0; i < animals.size(); i++)
//            animals[i].update();	
            animal.update();	
}

void wuAnimalXMLManager::draw(bool bDrawlines, int offX)
{
//        for (int i = 0; i < animals.size(); i++)
//            animals[i].draw(bDrawlines, offX);
		if(bReadyGo && !bGo)
			skinInit.draw(offX);

		if(bGo)
            animal.draw(bDrawlines, offX);	
}

void wuAnimalXMLManager::clear()
{
//  for (int i = 0; i < animals.size(); i++)
//		animals[i].clear();
//   animals.clear();
   skins.clear();
}

void wuAnimalXMLManager::touch(int _x,int _y, int forceX, int forceY)
{
 //   for (int i = 0; i < animals.size(); i++)
//		animals[i].touch(_x, _y, forceX, forceY);
}

void wuAnimalXMLManager::drag(int _x, int _y)
{
 //       for (int i = 0; i < animals.size(); i++)
 //           animals[i].drag(_x,_y);	
}

// reordena els skins segons la pos.x 
// ja que skins[] est� ordenat per tamany del blob.
void wuAnimalXMLManager::OrderSkins()
{
	float max_X=0;

	int size = skins.size();

	for(int j=0; j < size; j++)
	{
			float min_X_local=vw;
			int ordTmp = 0;

			for(int i=0; i < size; i++)
			{
				// busca el valor de posici� m�s petit sense comptar les posicions
				// que han sigut assignades fins ara (els majors de min_X)
				if( skins[i].posSkin.x	< min_X_local && skins[i].posSkin.x > max_X)
				{
					min_X_local = skins[i].posSkin.x;
					ordTmp = i;
				}
			}
			max_X = min_X_local;//skins[ ordTmp ].posSkin.x;
			wuSkin * _skin;
			_skin = &(skins[ordTmp]);
//			_skin.posSkin = skins[ordTmp].posSkin;
//			_skin.angSkin = skins[ordTmp].angSkin;
			skins.push_back(*_skin);
	}

	for(int i=0; i< size; i++)
		skins.erase(skins.begin());
}
