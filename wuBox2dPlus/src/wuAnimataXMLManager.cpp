#include "wuAnimataXMLManager.h"

wuAnimataXMLManager::wuAnimataXMLManager()
{

}

wuAnimataXMLManager::~wuAnimataXMLManager()
{
}

void wuAnimataXMLManager::setup(ofxBox2d * _box2d, string _XMLfilename, int _vw, int _vh)
{   
	XMLfilename = _XMLfilename;
	wuBase2dManager::setup(_box2d, _vw, _vh);
	bSkinOn = false;
	bGo = false;
	bReadyGo = false;
}

bool wuAnimataXMLManager::capture(ofImage *currImg, ofImage *bgImg)
{
	bool bCambiazo;

	if(bReadyGo)
	{
		// capturo nous bitxos i els passo l' array d' skins de peces
//		wuAnimata animata;
        animata.setup(box2d, XMLfilename, vw, vh, &skins, rectInit);
//		animatas.push_back(animata);
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
			cout << "animataXMLManager -> skins captured";
			// a partir d' ara només m' interessa el blob del bitxo muntat
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

void wuAnimataXMLManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob )
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

void wuAnimataXMLManager::update()
{
//        for (int i = 0; i < animatas.size(); i++)
//            animatas[i].update();	
            animata.update();	
}

void wuAnimataXMLManager::draw(bool bDrawlines, int offX)
{
//        for (int i = 0; i < animatas.size(); i++)
//            animatas[i].draw(bDrawlines, offX);
		if(bReadyGo && !bGo)
			skinInit.draw(offX);

		if(bGo)
            animata.draw(bDrawlines, offX);	
}

void wuAnimataXMLManager::clear()
{
//  for (int i = 0; i < animatas.size(); i++)
//		animatas[i].clear();
//   animatas.clear();
   skins.clear();
}

void wuAnimataXMLManager::touch(int _x,int _y, int forceX, int forceY)
{
 //   for (int i = 0; i < animatas.size(); i++)
//		animatas[i].touch(_x, _y, forceX, forceY);
}

void wuAnimataXMLManager::drag(int _x, int _y)
{
 //       for (int i = 0; i < animatas.size(); i++)
 //           animatas[i].drag(_x,_y);	
}

// reordena els skins segons la pos.x 
// ja que skins[] està ordenat per tamany del blob.
void wuAnimataXMLManager::OrderSkins()
{
	float max_X=0;

	int size = skins.size();

	for(int j=0; j < size; j++)
	{
			float min_X_local=vw;
			int ordTmp = 0;

			for(int i=0; i < size; i++)
			{
				// busca el valor de posició més petit sense comptar les posicions
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
