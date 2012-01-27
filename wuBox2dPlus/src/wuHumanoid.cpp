#include "wuHumanoid.h"

wuHumanoid::wuHumanoid()
{
}

wuHumanoid::~wuHumanoid()
{
}

void wuHumanoid::setup(ofxBox2d * _box2d, int _vw, int _vh){

	wuEnte::setup(_box2d, _vw, _vh);

	gest_fly_R.setup();
	gest_fly_L.setup();
	gest_run_R.setup();
	gest_run_R.setTime(1500);
	gest_run_L.setup();
	gest_run_L.setTime(1500);

	bKameame = false;

	scale.x = 0.25; // % original kinect size
	scale.y = 0.25;

	offY = 0;
	old_offY = 0;
	Yfloor = 220;
}

void wuHumanoid::setScale(float _scale){
   	scale.x = _scale;
	scale.y = _scale;
}

void wuHumanoid::setSkel(Skeleton _skel)
{
	skel = _skel;

	// ***** defineixo que la base estarà als peus *************
	if (skel.Rfoot.y > skel.Lfoot.y)
			foot_base_pos.y = skel.Rfoot.y*scale.y -basedim;
		else
			foot_base_pos.y = skel.Lfoot.y*scale.y -basedim;

	foot_base_pos.x = skel.torso.x*scale.x;

}

void wuHumanoid::update()
{
	// MOVIMENT
	checkMotion();
	wuEnte::update();
}

void wuHumanoid::draw(bool bDrawlines, int _offX)
{
	ofSetColor(255, 255, 255);

    // pinta skin
	if (skel.bDetected)
	{
		wuEnte::draw(bDrawlines, _offX);
		
		if(bDrawlines && offX==0)
		{
			// DRAW JOINTS
			ofSetColor(255,0,0);
			ofCircle(skel.head.x*scale.x+framePos.x, skel.head.y*scale.y+framePos.y, 3);
			ofCircle(skel.Lelbow.x*scale.x+framePos.x, skel.Lelbow.y*scale.y+framePos.y, 3);
			ofCircle(skel.Lhand.x*scale.x+framePos.x, skel.Lhand.y*scale.y+framePos.y, 3);
			ofCircle(skel.Lshoulder.x*scale.x+framePos.x, skel.Lshoulder.y*scale.y+framePos.y, 3);
			ofCircle(skel.neck.x*scale.x+framePos.x, skel.neck.y*scale.y+framePos.y, 3);
			ofCircle(skel.torso.x*scale.x+framePos.x, skel.torso.y*scale.y+framePos.y, 3);
			ofCircle(skel.Lhip.x*scale.x+framePos.x, skel.Lhip.y*scale.y+framePos.y, 3);
			ofCircle(skel.Rhip.x*scale.x+framePos.x, skel.Rhip.y*scale.y+framePos.y, 3);
			ofCircle(skel.Relbow.x*scale.x+framePos.x, skel.Relbow.y*scale.y+framePos.y, 3);
			ofCircle(skel.Rhand.x*scale.x+framePos.x, skel.Rhand.y*scale.y+framePos.y, 3);
			ofCircle(skel.Rshoulder.x*scale.x+framePos.x, skel.Rshoulder.y*scale.y+framePos.y, 3);
			ofCircle(skel.Lknee.x*scale.x+framePos.x, skel.Lknee.y*scale.y+framePos.y, 3);
			ofCircle(skel.Rknee.x*scale.x+framePos.x, skel.Rknee.y*scale.y+framePos.y, 3);
			ofCircle(skel.Lfoot.x*scale.x+framePos.x, skel.Lfoot.y*scale.y+framePos.y, 3);
			ofCircle(skel.Rfoot.x*scale.x+framePos.x, skel.Rfoot.y*scale.y+framePos.y, 3);

		}

		if(bKameame)
		{
			ofSetColor(0,0,255);
			ofCircle(skel.Lhand.x*scale.x + +framePos.x + offX, skel.Lhand.y*scale.y + +framePos.y, 5); 
			ofCircle(skel.Lhand.x*scale.x + +framePos.x + offX, skel.Lhand.y*scale.y + +framePos.y, 10); 
		}

	}

}

void wuHumanoid::checkMotion()
{

	// inclinació del cos
	float lineX = skel.neck.x - skel.head.x;
	float lineY = skel.neck.y - skel.head.y;
	float SkelAngleCap = -atan2(lineX,lineY)+(PI/2);
	SkelAngleCap = (SkelAngleCap - 1.5) * 10.;

    ofPoint p;
	p = base.getPosition();

	// RUN
	int Run_L;
	Run_L = gest_run_L.update(skel.Lfoot.x);
	int Run_R;
	Run_R = gest_run_R.update(skel.Rfoot.x);

	if(Run_L>0 && Run_R>0)
	{	
		if(skel.torso.x > skel.head.x + 10 )
		    base.moveTo(p.x-8, p.y);
		if(skel.torso.x < skel.head.x - 10 )
		    base.moveTo(p.x+8, p.y);


	}
	else
	{
		// FLY
		int Fly_left;
		Fly_left = gest_fly_L.update(skel.Lhand.y);
		int Fly_right;
		Fly_right = gest_fly_R.update(skel.Rhand.y);
	
		bool estirats = (abs(skel.Lhand.x-skel.head.x)>50 && abs(skel.Rhand.x-skel.head.x)>50);

		if(Fly_left>0 && Fly_right>0 && estirats)
		{	
			base.setVelocity(0,0);
			base.moveTo(p.x+SkelAngleCap, p.y-(Fly_left+Fly_right));
		}
		else
		{

			// JUMP
			if ( abs(offX-old_offX) < 10 && abs(offY-old_offY) < 10 && skel.torso.y<300)
	 		{
				// oju. aq numero depen de la pos del kinect
				if(skel.torso.y<Yfloor)
					base.moveTo(p.x+10*(offX-old_offX), p.y+14*(offY-old_offY));
				else
				    base.moveTo(p.x+2*(offX-old_offX), p.y+(offY-old_offY));
			}
		}
	}

    old_offX = offX;
    old_offY = offY;

	offX = foot_base_pos.x;
	offY = foot_base_pos.y;

	framePos.x = p.x-offX;
	framePos.y = p.y-offY;

	// kameame?
	//	(( skel.Lhand.x> skel.head.x && skel.Rhand.x> skel.head.x) || ( skel.Lhand.x< skel.head.x && skel.Rhand.x< skel.head.x))  
	bool bmansmateixcostat=(( skel.Lhand.x> skel.head.x && skel.Rhand.x> skel.head.x) || ( skel.Lhand.x< skel.head.x && skel.Rhand.x< skel.head.x));
	bool bseparatsdelcap=( abs(skel.Lhand.x-skel.head.x)>55 && abs(skel.Rhand.x-skel.head.x)>55);
	if (bmansmateixcostat && bseparatsdelcap)
		bKameame = true;
	else
		bKameame = false;

    p = base.getPosition();
	if (p.y > vh-5)
		base.moveTo(p.x, vh-5);
	if (p.x > vw-5)
		base.moveTo(vw-5, p.y);
	if (p.x < 5)
		base.moveTo(5, p.y);

}



void wuHumanoid::setFloor()
{
	Yfloor = skel.torso.y - 20;
	cout << "new floor: " << Yfloor << endl;
}

ofPoint wuHumanoid::isKameame()
{
	ofPoint kame_hands;
	kame_hands.x = -1;
	kame_hands.y = -1;

	if(bKameame)
	{
		kame_hands.x = (skel.Lhand.x+skel.Rhand.x)/2.0*scale.x + framePos.x;
		kame_hands.y = (skel.Lhand.y+skel.Rhand.y)/2.0*scale.y + framePos.y;
	}
	// si no està en kameame (mans juntes) retorna -1
	return kame_hands;
}
ofPoint wuHumanoid::headPos()
{
	ofPoint head_pt;
	
	head_pt.x = skel.head.x*scale.x + framePos.x;
	head_pt.y = skel.head.y*scale.y + framePos.y;
	return head_pt;
}