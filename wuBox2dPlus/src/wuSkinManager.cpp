#include "wuSkinManager.h"

wuSkinManager::wuSkinManager()
{
}

wuSkinManager::~wuSkinManager()
{
}

bool wuSkinManager::capture(ofImage *currImg, ofImage *bgImg)
{
	bool bCambiazo = true;

	wuBaseManager::capture(currImg, bgImg);

	return bCambiazo;
}

void wuSkinManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob)
{
	wuSkin skin;
	skin.setup(_skin, rect);
	skins.push_back(skin);
}

void wuSkinManager::draw(int offX)
{
    for (int i = 0; i < skins.size(); i++)
        skins[i].draw(offX);	
}

void wuSkinManager::clear()
{
        for (int i = skins.size()-1; i >= 0; i--)
        {
			skins.erase(skins.begin()+i);
		}
}

// reordena els skins segons la pos.x 
// ja que skins[] està ordenat per tamany del blob.
void wuSkinManager::OrderSkins()
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
vector <wuSkin> * wuSkinManager::getSkin()
{
	return &skins;
}

ofPoint wuSkinManager::getPosition(int i)
{
	ofPoint _pos;
	_pos.x=0;
	_pos.y=0;

	if( i > -1 && i< skins.size() )
		_pos = skins[i].posSkin;
	else
		cout << "getPosition->error:quin skin?";

	return _pos;

}

ofPoint wuSkinManager::getPosition()
{
	if ( skins.size()!=1)
		cout << "getPosition->error:no tens 1 sol skin";

	return skins[0].posSkin;
}

float wuSkinManager::getRotation()
{
	if ( skins.size()!=1)
		cout << "getPosition->error:no tens 1 sol skin";

	return skins[0].angSkin;
}

float wuSkinManager::getRotation(int i)
{
	return skins[i].angSkin;
}



int wuSkinManager::getNumberSkins()
{
	return skins.size();
}

void wuSkinManager::setPosition(int i, ofPoint _pos)
{
	if( i > -1 && i< skins.size() )
		skins[i].posSkin =_pos;
	else
		cout << "setPosition->error:quin skin?";
}

void wuSkinManager::setPosition(ofPoint _pos)
{
	if( skins.size() == 1)
		skins[0].posSkin = _pos;
	else
		cout << "setPosition->error:no tinc 1 sol skin";
}

void wuSkinManager::setRotation(int i, float _ang)
{
	if( i > -1 && i< skins.size() )
		skins[i].angSkin = _ang;
	else
		cout << "setRotation->error:quin skin?";
}

void wuSkinManager::setRotation(float _ang)
{
	if( skins.size() == 1)
		skins[0].angSkin = _ang;
	else
		cout << "setRotation->error:no tinc 1 sol skin";
}

int wuSkinManager::isTouched(int _x,int _y)
{
	int whosTouched;

	whosTouched = -1;
	// returns -1 if nobody is touched

	for (int i = 0; i < skins.size(); i++)
	{
		if( (_x > skins[i].posSkin.x-skins[i].skin.getWidth()/2) && (_x < skins[i].posSkin.x + skins[i].skin.getWidth()/2) && (_y > skins[i].posSkin.y - skins[i].skin.getHeight()/2) && (_y < skins[i].posSkin.y + skins[i].skin.getHeight()/2) ) 
			whosTouched = i;
	}
	// returns object number
	return whosTouched;
}
