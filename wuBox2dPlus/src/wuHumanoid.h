
#ifndef wu_HUMANOID_H
#define wu_HUMANOID_H

#pragma once
#include "wuEnte.h"
#include "wuGestures.h"
#include "skelstruct.h"

enum {
    // BODY PIECES
	HEAD,
	TORSO,
	LEFT_ARM,
	HIP,
	LEFT_LEG,
	LEFT_HAND,
	LEFT_FOOT,
	RIGHT_ARM,
	RIGHT_LEG,
	RIGHT_HAND,
	RIGHT_FOOT
};

class wuHumanoid : public wuEnte
{
    public:
        wuHumanoid();
        ~wuHumanoid();

        virtual void setup(ofxBox2d * _box2d, int _vw, int _vh);
		virtual void update();
        virtual void draw(bool pinta_bg=false, int offX=0);
        virtual void checkMotion(void);
		virtual void setFloor();
		virtual void setSkel(Skeleton _skel);
		virtual void setScale(float _scale);
		virtual ofPoint isKameame();
		virtual ofPoint headPos();

		Skeleton skel;

		// gestures
		wuGest_shake gest_fly_R;
		wuGest_shake gest_fly_L;
		wuGest_shake gest_run_R;
		wuGest_shake gest_run_L;

//		int kinFrameX, kinFrameY;
		float old_offX;
		float old_offY;
		float offX;
		float offY;

		ofPoint foot_base_pos;

		int Yfloor;
		bool bKameame;

};
#endif

