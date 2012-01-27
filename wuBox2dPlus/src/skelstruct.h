#ifndef wu_SKELSTRUCT_H
#define wu_SKELSTRUCT_H

#pragma once
#include "ofMain.h"

struct Skeleton
{
	ofPoint head;
	ofPoint neck;
	ofPoint Lshoulder;
	ofPoint Rshoulder;
	ofPoint Lelbow;
	ofPoint Relbow;
	ofPoint Lhand;
	ofPoint Rhand;
	ofPoint torso;
	ofPoint Lhip;
	ofPoint Rhip;
	ofPoint Lknee;
	ofPoint Rknee;
	ofPoint Lfoot;
	ofPoint Rfoot;
	bool bDetected;
};


#endif

