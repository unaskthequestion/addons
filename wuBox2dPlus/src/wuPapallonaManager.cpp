#include "wuPapallonaManager.h"

wuPapallonaManager::wuPapallonaManager()
{
}

wuPapallonaManager::~wuPapallonaManager()
{
}

bool wuPapallonaManager::capture(ofImage *currImg, ofImage *bgImg)
{
	bool bCambiazo = true;

	wuBaseManager::capture(currImg, bgImg);

	return bCambiazo;
}

void wuPapallonaManager::addBitxo(ofImage *_skin, ofRectangle rect)
{
	wuPapallona papallona;
	papallona.setup(_skin, rect);
	papallones.push_back(papallona);
}

void wuPapallonaManager::update()
{
        for (int i = 0; i < papallones.size(); i++)
            papallones[i].update();	

		for (int i = papallones.size()-1; i >= 0; i--)
	    {
			// destroy bitxos que marxen fora de la pantalla
			if (papallones[i].getPosition().y > vh || papallones[i].getPosition().y < 0 || papallones[i].getPosition().x > vw || papallones[i].getPosition().x < 0) 
				papallones.erase(papallones.begin()+i);
		}

}

void wuPapallonaManager::draw(int offX)
{
        for (int i = 0; i < papallones.size(); i++)
            papallones[i].draw(offX);	
}

void wuPapallonaManager::clear()
{
	papallones.clear();
}

