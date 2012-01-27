#ifndef _Blade_h
#define _Blade_h

#include "ofMain.h"
#include "ofxBox2d.h"
#include "PolygonJoint.h"
#include "MSAPerlin.h"7

#define BLADE_SEGMENTS 7
#define DIMINISHING_RATE 0.9
#define MAX_HEIGHT 100
#define MIN_HEIGHT 25
#define MAX_WIDTH MAX_HEIGHT/20
#define MIN_WIDTH 1
#define STIFFNESS 0.03
#define DAMPING 100.1
#define	MASS 300

class wuBlade {
	//ofxBox2d		box2d;
	b2World			*world;
	
	ofxBox2dCircle	ballJoints[BLADE_SEGMENTS];
	PolygonJoint	joints[BLADE_SEGMENTS];
	bool			bDrawBallJoints;
	bool			alive;
	ofPoint			attractionPoint;
	bool			bAttractionPoint;
	
	float	mWidth;
	float	mHeight;
	ofPoint	mLoc;
	float	mDamping;
	
	int	mouseX;
	int mouseY;
	
	MSA::Perlin mPerlin;
	
public:
	wuBlade(){
		//ofLog(OF_LOG_NOTICE, "- Blade constructor -");
		world = NULL;
		alive = false;
		mWidth = ofRandom(MIN_WIDTH, MAX_WIDTH);
		mHeight = ofRandom(MIN_HEIGHT, MAX_HEIGHT);
		mLoc = ofPoint(ofRandom(0, ofRandomWidth()), ofRandom(0, ofRandomHeight()) - mHeight);
		
	};
	
	wuBlade(ofPoint loc){
		world = NULL;
		alive = false;
		mLoc = loc;
		mWidth = ofRandom(MIN_WIDTH, MAX_WIDTH);
		mHeight = ofRandom(MIN_HEIGHT, MAX_HEIGHT);
	};
	
	// 'w' and 'h' must be values from 0 to 1
	wuBlade(ofPoint loc, float w, float h){
		world = NULL;
		alive = false;
		
		mLoc = loc;
		
		mWidth = ofMap(w, 0, 1, MIN_WIDTH, MAX_WIDTH);
		mHeight = ofMap(h, 0, 1, MIN_HEIGHT, MAX_HEIGHT);
	};
	
	void setup(b2World * w){
		world = w;
		//ofLog(OF_LOG_NOTICE, "- Blade setup -");
		if(world == NULL){
			ofLog(OF_LOG_NOTICE, "- box2d world needed -");
			return;
		}
		
		bDrawBallJoints = false;
		alive = true;
		bAttractionPoint = false;
		
		// the joints
		float x = mLoc.x; 
		float y = mLoc.y;
		float h = mHeight;
		float r = mWidth;
		mDamping = DAMPING;// * ofRandom(1, DAMPING);
		ballJoints[0].setPhysics(MASS, STIFFNESS, mDamping);
		ballJoints[0].setup(world, x, y, r, true);
		
		
		for(int i=1; i<BLADE_SEGMENTS; i++) {
			h *= 0.3;
			y -= h;
			r *= DIMINISHING_RATE;
			ballJoints[i].setPhysics(MASS, STIFFNESS, mDamping);
			if (i==0) {			
			}else{
				ballJoints[i].setup(world, x, y, r);
			}
			
		}
		// connect all the ball joints
		float bw = r;
		float tw;
		for(int i=1; i<BLADE_SEGMENTS; i++) {
			tw = bw*0.5;
			joints[i].setWorld(world);
			joints[i].addJoint(bw, tw, ballJoints[i].body, ballJoints[i-1].body, 3.0, 0.5);
			
			bw = tw;
		}
		
		
	};
	
	void update(){
		if(bAttractionPoint){
			float strength = 8.0f;
			float damping  = 0.7f;
			
			ballJoints[BLADE_SEGMENTS-1].addAttractionPoint(attractionPoint.x, attractionPoint.y, strength);
			ballJoints[BLADE_SEGMENTS-1].addDamping(damping, damping);
			
		}
	};
	
	void draw(int x=0, int y=0){
		if(!alive) return;
        
        vector<ofPoint*> points;
		
		ofFill();
		if(bDrawBallJoints){
			for(int i=0; i<BLADE_SEGMENTS; i++) ballJoints[i].draw();
		}
		for(int i=0; i<BLADE_SEGMENTS; i++) joints[i].draw(x,y);
		ofNoFill();
	};
	
	void mouseMoved(int x, int y){
		mouseX = x;
		mouseY = y;
	};
	
	void setDrawBallJoints(bool b){
		bDrawBallJoints = b;
	};
	
	bool isAlive(){
		return alive;
	};
	
	void setAttractionPoint(float x, float y){
		attractionPoint.set(x, mLoc.y + mHeight, 0);
	};
		
	ofPoint getLoc(){
		return mLoc;
	};
	
	void enableAttractionPoint(bool b){
		bAttractionPoint = b;
	};
};

#endif
