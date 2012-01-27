#include "wuSimpleMovie.h"

wuSimpleMovie::wuSimpleMovie()
{

}

wuSimpleMovie::~wuSimpleMovie()
{
}

void wuSimpleMovie::setup(string _filename)
{
	movie.loadMovie(_filename);
//	movie.stop();
    movie.play();
	movie.setLoopState(OF_LOOP_NONE);
	movie.idleMovie();
	bPlayMovie = false;
	bCambiazo = false;
	bDragOn = false;
	posSkin.x = 0;
	posSkin.y = 0;
	offset.x = 0;
	offset.y = 0;
    vw = movie.getWidth();
    vh = movie.getHeight();
    
}

void wuSimpleMovie::update()
{
	if(bPlayMovie)
	{
		int f = movie.getCurrentFrame();
		int t = movie.getTotalNumFrames();
		if (f >= t) {
			movie.stop();
			movie.setFrame(1);
			bPlayMovie=false;
		}else
		    movie.idleMovie();
	}else	{ 
		if(bCambiazo)
			movie.setFrame(1);
	}
}

void wuSimpleMovie::draw(bool bDrawLines, int offX)
{
	if(bCambiazo || (bDrawLines && offX==0))
	{

		// draw skin
		ofPushMatrix();
			ofEnableAlphaBlending();
        movie.draw(posSkin.x+offX, posSkin.y, vw, vh);
			ofDisableAlphaBlending();
		ofPopMatrix();
	}
}

void wuSimpleMovie::setPosition(ofPoint _pos)
{
	posSkin =_pos;
}




void wuSimpleMovie::dragOff()
{
	bDragOn = false;
}

void wuSimpleMovie::drag(int _x,int _y)
{
	if(!bDragOn)
	{
		offset.x = _x - posSkin.x;
		offset.y = _y - posSkin.y;
		bDragOn = true;
	}
	
	posSkin.x = _x -offset.x;
	posSkin.y = _y -offset.y;
}

bool wuSimpleMovie::play()
{
	bool bCambiazoSend = false;
    
    movie.setFrame(1);
	movie.play();
	movie.setLoopState(OF_LOOP_NONE);

	if(!bCambiazo)
	{
		bCambiazo = true;
		bCambiazoSend = true;
	}
	else
	{
		bPlayMovie=true;
//		movie.setFrame(1);
//		movie.play();
//		movie.setLoopState(OF_LOOP_NONE);
	}

	return bCambiazoSend; 
}

void wuSimpleMovie::scale(float f){
    vw *= f;
    vh *= f;
}
