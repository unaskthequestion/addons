#include "wuMovieVec.h"

wuMovieVec::wuMovieVec()
{

}

wuMovieVec::~wuMovieVec()
{
}

void wuMovieVec::setup(ofxBox2d * _box2d, int _vw, int _vh, string _filename)
{
    box2d = _box2d;
    vw = _vw;
    vh = _vh;
	num_movies = 0;
	status = 0;

	for(int i=0; i<MAX_MOVIES; i++) {
		movies[num_movies].setup(box2d, vw, vh, _filename);
//		movies[num_movies].loop(true);
//		movies[num_movies].velZero(true);
	}
}

bool wuMovieVec::capture(ofxCvColorImage *color, ofxCvGrayscaleImage * grayDiff)
{
	bool bCambiazo = false;

	switch(status)
	{
	case 0:
		if ( num_movies < MAX_MOVIES)
		{
			movies[num_movies].capture(color,grayDiff);
			num_movies++;
		}
		status++;
		bCambiazo = true;
		break;
	case 1:
		movies[num_movies-1].go();
		status++;
		break;
	case 2:
		movies[num_movies-1].removeRetall();
		status=0;
		break;
	}
	return bCambiazo;
}
void wuMovieVec::draw(bool bDrawlines, int offX)
{
	for(int i=0; i<num_movies; i++) {
		movies[i].draw(bDrawlines,offX);
	}
}

void wuMovieVec::update()
{
	for(int i=0; i<num_movies; i++) {
		movies[i].update();
	}
}

void wuMovieVec::clear()
{
	for(int i=0; i<num_movies; i++) {
		movies[i].clear();
	}
	num_movies=0;
}


void wuMovieVec::isTouched(int _x,int _y)
{
	for(int i=0; i<num_movies; i++) {
		// retorna quina és la bola tocada (una d' elles).
		// si no n'hi ha cap, retorna -1
		bool bolasel = movies[i].isTouched(_x,_y);

		if( bolasel)
			movies[i].setPosition(_x,_y);
	}

}
void wuMovieVec::Touch(int _x,int _y, int forceX, int forceY)
{
	for(int i=0; i<num_movies; i++) {
		movies[i].Touch(_x,_y, forceX, forceY);
	}


}