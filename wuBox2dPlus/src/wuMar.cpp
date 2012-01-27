#include "wuMar.h"

wuMar::wuMar()
{

}

wuMar::~wuMar()
{
}



void wuMar::setup(ofImage *_skin, ofRectangle rect, vector <ofPoint> *_simpleCountour)
{
	// solidShape with skin
	wuBaseSkin::setSkin(_skin, rect);
	// blavós semi-transparent
	wuBaseSkin::setColor(200,200,250,190);

	simpleCountour.clear();

	for(int j=0; j < (*_simpleCountour).size(); j++) {
		simpleCountour.push_back( (*_simpleCountour)[j] );
	}
				
}

void wuMar::draw(bool bDrawlines, int offX)
{
	wuBaseSkin::draw(offX);

    if(bDrawlines && offX==0)
    {
        ofSetColor(0,255,255);
		for(int j=simpleCountour.size()-1; j>-1; j--) 
			ofCircle(simpleCountour[j].x, simpleCountour[j].y, 5);
    }

}

void wuMar::clear()
{
	simpleCountour.clear();
}

int wuMar::getNivell(ofPoint pos)
{
	int dis_min=20000;
	ofPoint p_minim;
	p_minim.x=2000;
	p_minim.y=2000;

	for(int j=simpleCountour.size()-1; j>0; j--) {
		// el punt de contorn + proper en un rang de +- 60 pixels
		if ( (abs(simpleCountour[j].x-pos.x)<100) && ((((int)simpleCountour[j].x-(int)pos.x)^2)+(((int)simpleCountour[j].y-(int)pos.y)^2) < dis_min) )
		{
			p_minim.x = simpleCountour[j].x;
			p_minim.y = simpleCountour[j].y;
			dis_min = (((int)p_minim.x-(int)pos.x)^2)+(((int)p_minim.y-(int)pos.y)^2);
		}
	}

	return (int)p_minim.y;
}
