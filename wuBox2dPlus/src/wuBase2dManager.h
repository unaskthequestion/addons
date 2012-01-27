#ifndef wu_BASE2DMANAGER_H
#define wu_BASE2DMANAGER_H

#pragma once
#include "ofMain.h"
#include "wuBaseManager.h"
#include "ofxBox2d.h"


class wuBase2dManager : public wuBaseManager
{
    public:
        wuBase2dManager();
        ~wuBase2dManager();

    void setup(ofxBox2d * _box2d, int _vw, int _vh);

	// box2d
    ofxBox2d * box2d;

};
#endif

