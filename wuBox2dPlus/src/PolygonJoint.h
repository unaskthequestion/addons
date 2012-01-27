/*
 *  CustomParticle.h
 *  ofxBox2DExample
 *
 *  Created by ... on 09/01/2011.
 *  Copyright 2011. All rights reserved.
 *
 */
#ifndef _PolygonJoint
#define _PolygonJoint


#include "ofMain.h"
#include "ofxBox2d.h"


class PolygonJoint : public ofxBox2dJoint {
	float mBottomWidth;
	float mTopWidth;
	
	public:
	void addJoint(float bottomWidth, float topWidth, b2Body * a, b2Body * b, float stiffness=3.0f, float damping=0.6f ) {
		mBottomWidth = bottomWidth;
		mTopWidth = topWidth;
		ofxBox2dJoint::addJoint(a, b, stiffness, damping);
	}
	void setup(){
		
	};
	void update();
	void draw(int x=0, int y=0){
		
		if(!alive) return;
		
		ofEnableAlphaBlending();
//		ofSetColor(255, 0, 255, alpha);
		
		b2Vec2 p1 = joint->GetAnchor1();
		b2Vec2 p2 = joint->GetAnchor2();
		
		p1 *= OFX_BOX2D_SCALE;
		p2 *= OFX_BOX2D_SCALE;
		
		//ofSetColor(0, 128, 32, alpha);
        ofPushMatrix();
        ofTranslate(x, y);
		ofBeginShape();
		ofVertex(p1.x-mTopWidth, p1.y);
		ofVertex(p2.x-mBottomWidth, p2.y);
		ofVertex(p2.x+mBottomWidth, p2.y);
		ofVertex(p1.x+mTopWidth, p1.y);		
		ofEndShape(true);
        ofPopMatrix();
		
		//ofLine(p1.x, p1.y, p2.x, p2.y);	   
		ofDisableAlphaBlending();
	};
	
	ofColor color;
};

#endif
