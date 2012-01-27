#ifndef wu_MOVIEVEC_H
#define wu_MOVIEVEC_H

#define MAX_MOVIES 1

#pragma once
#include "wuMovieMonsterPlus.h"

class wuMovieVec 
{
    public:
        wuMovieVec();
        ~wuMovieVec();


		void setup(ofxBox2d * _box2d, int _vw, int _vh, string _filename);
        void update();
        bool capture(ofxCvColorImage *color, ofxCvGrayscaleImage * grayDiff);
        void draw(bool pinta_bg=false, int offX=0);
        void clear(void);
		void Touch(int _x,int _y, int forceX=300, int forceY=0);
		void isTouched(int _x,int _y);

        wuMovieMonsterPlus movies[MAX_MOVIES];

		int num_movies;

		int status;

		// box2d
        ofxBox2d * box2d;
		int vw, vh;

};
#endif

