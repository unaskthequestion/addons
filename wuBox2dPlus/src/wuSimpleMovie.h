#ifndef wu_SIMPLEMOVIE_H
#define wu_SIMPLEMOVIE_H

#pragma once
#include "ofMain.h"
//#include "ofxAlphaVideoPlayer.h"
#include "ofVideoPlayer_alpha.h"

class wuSimpleMovie
{
public:
    wuSimpleMovie();
    ~wuSimpleMovie();
    
    void setup(string _filename);
    void update();
    void draw(bool bDrawLines=false, int offX=0);
    void setPosition(ofPoint _pos);
    void drag(int _x,int _y);
    void dragOff();
    bool play();
    void scale(float f);
    
    ofVideoPlayer_alpha	movie;
    ofPoint posSkin, offset;
    bool bPlayMovie, bCambiazo, bDragOn;
    int vw, vh;
};
#endif

