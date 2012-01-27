#ifndef wu_GESTURES_H
#define wu_GESTURES_H

#pragma once
#include "ofMain.h"

class wuGest_shake
{
    public:
        wuGest_shake();
        ~wuGest_shake();

        void setup();
        int update(int _x);
		void setTime(int _time);

	float sTreshold;  
	float accx;  
	int trig;  
	int startshake;  
	int shake;  
	int shakemaxnumber ;  
	int timeofgesture;  
	int oldx, x;

};
#endif

