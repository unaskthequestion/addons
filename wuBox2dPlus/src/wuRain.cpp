#include "wuRain.h"

wuRain::wuRain()
{

}

wuRain::~wuRain()
{
//    delete grayImage;
}

void wuRain::setup(ofxBox2d * _box2d, int _vw, int _vposx, int _vposy){
    box2d = _box2d;
    vw = _vw;
    vposx = _vposx;
	vposy = _vposy;
	isAlive = false;
}


void wuRain::draw(int offX)
{
	for(int i=0; i<gotes.size(); i++) {
		gotes[i].draw(offX);
	}

}

void wuRain::update()
{
	if (isAlive)
		addGota();
	else{
		if(gotes.size() > 0 && ofRandom(0, 5) < 1)
		{
			gotes.begin()->destroyShape();
			gotes.erase(gotes.begin());
		}
	}

	if (gotes.size() > NUM_GOTES) {
			gotes.begin()->destroyShape();
			gotes.erase(gotes.begin());
	}
}

void wuRain::update(int _vposx, int _vposy){
    vposx = _vposx;
	vposy = _vposy;

	if (isAlive)
		addGota();
	else{
		if(gotes.size() > 0 && ofRandom(0, 5) < 1)
		{
			gotes.begin()->destroyShape();
			gotes.erase(gotes.begin());
		}
	}

	if (gotes.size() > NUM_GOTES) {
			gotes.begin()->destroyShape();
			gotes.erase(gotes.begin());
	}
}

void wuRain::addGota()
{
		float x = ofRandom(vposx-(vw/2), vposx+(vw/2));
		float y = vposy+10;
		float r = ofRandom(1, 5);

		// Mass Bounce Friction
		wuGota p;
		p.setPhysics(0.0001, 0.23, 0.9);
		p.setup(box2d->getWorld(), x, y, r);
		gotes.push_back(p);
}

void wuRain::startRain()
{
	isAlive = true;
}
void wuRain::stopRain()
{
	isAlive = false;
}