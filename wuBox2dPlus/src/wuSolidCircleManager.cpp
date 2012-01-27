#include "wuSolidCircleManager.h"

wuSolidCircleManager::wuSolidCircleManager()
{

}

wuSolidCircleManager::~wuSolidCircleManager()
{
}

bool wuSolidCircleManager::capture(ofImage *currImg, ofImage *bgImg)
{
	bool bCambiazo = true;

	wuBaseManager::capture(currImg, bgImg);

	return bCambiazo;
}

void wuSolidCircleManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob )
{
	wuSolidCircle circle;
	circle.setup(box2d, _skin, rect);
	circles.push_back(circle);
}

void wuSolidCircleManager::draw(bool bDrawlines, int offX)
{
        for (int i = 0; i < circles.size(); i++)
            circles[i].draw(bDrawlines, offX);	
}

void wuSolidCircleManager::update()
{
        for (int i = 0; i < circles.size(); i++)
            circles[i].update();	

		// destroy off-screen positions
		for (int i = circles.size()-1; i >= 0; i--)
        {
			if (circles[i].getPosition().y > vh)
				circles.erase(circles.begin()+i);
		}
}

void wuSolidCircleManager::clear()
{
    for (int i = 0; i < circles.size(); i++)
		circles[i].clear();
	circles.clear();
}

void wuSolidCircleManager::touch(int _x,int _y, int forceX, int forceY)
{
    for (int i = 0; i < circles.size(); i++)
		circles[i].touch(_x, _y, forceX, forceY);
}

void wuSolidCircleManager::drag(int _x,int _y)
{
    for (int i = 0; i < circles.size(); i++)
		circles[i].drag(_x, _y);
}