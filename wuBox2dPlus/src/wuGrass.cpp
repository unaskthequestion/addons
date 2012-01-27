#include "wuGrass.h"

wuGrass::wuGrass() {
//    init();
}

void wuGrass::setup(ofxBox2d * _box2d){
	box2d = _box2d;
		if(box2d == NULL){
			ofLog(OF_LOG_NOTICE, "- box2d world needed -");
			return;
		}

		mBladeCount = 0;
		mLoc = ofPoint(0,ofGetHeight()-50); // grass is at the bottom by default
		mWidth = ofGetWidth();
//		mBladePoints = *bladePoints;

		ofLog(OF_LOG_NOTICE, "- Grass created -");
};

void wuGrass::setup(ofxBox2d * _box2d, vector<ofPoint> &_points){
		
		box2d = _box2d;
		if(box2d == NULL){
			ofLog(OF_LOG_NOTICE, "- box2d world needed -");
			return;
		}

		mBladeCount = 0;
		mLoc = ofPoint(0,ofGetHeight()-50); // grass is at the bottom by default
		mWidth = ofGetWidth();
//		mBladePoints = *bladePoints;

		ofLog(OF_LOG_NOTICE, "- Grass created -");

		grassPoints.clear();
		for(int i=0; i < _points.size(); i++)
		{
			ofPoint p;
			p = _points[i];
            grassPoints.push_back(p);
		}
		setFieldFromPoints(grassPoints);
};
void wuGrass::update(){

		for (int i=0; i < mBlades.size(); i++) {
			mBlades[i].update();
		}
};

void wuGrass::draw(int x, int y){
		for (int i=0; i < mBlades.size(); i++) {
			mBlades[i].draw(x,y);
		}
};

void wuGrass::mouseMoved(int x, int y){
		mouseX = x;
		mouseY = y;

		for (int i=0; i < mBlades.size(); i++) {
			if (mouseX<0 || mouseX > ofGetWidth() || mouseY < 0 || mouseY > ofGetHeight()) {
				mBlades[i].enableAttractionPoint(false);
			}else {
				mBlades[i].enableAttractionPoint(true);
				mBlades[i].setAttractionPoint(mouseX, mouseY);
			}
		}

};

//----------------------------------------------------------------------------
	// Different kinds of grass fields
void wuGrass::setFlatField(){

		for (int i=0; i < MAX_NUM_BLADES; i++) {
			float rand = ofMap(ofRandomWidth(), 0, ofGetWidth(), mLoc.x, mWidth);
			float x = ofRandom(mLoc.x, rand);
			addBlade(ofPoint(x, mLoc.y));
		}

};

void wuGrass::setFieldFromPoints(vector<ofPoint> &points){
		for (int i=0; i < MAX_NUM_BLADES; i++) {
			int rand = ofRandom(0, points.size());
			ofPoint point = points[rand];
			addBlade(point);
			mBlades.back().setup(box2d->world);
		}
};

void wuGrass::setRandomField(){
		for (int i=0; i<MAX_NUM_BLADES; i++) {
			float x = ofRandomWidth();
			float y = ofRandomHeight();
			addBlade(ofPoint(x,y));
		}
};
//----------------------------------------------------------------------------!!
void wuGrass::addBlade(ofPoint pt){
		//ofLog(OF_LOG_NOTICE, "- Grass.addBlade() -");
		mBlades.push_back(wuBlade(pt, ofRandom(0,1), ofRandom(0, 1)));
};

void wuGrass::setBladePoints(vector<ofPoint> points){
		mBladePoints = points;
};

void wuGrass::setLoc(float x, float y){
		mLoc.set(x,y,0);
};

void wuGrass::setWidth(float w){
		mWidth = w;
};

//----------------------------------------------------------------------------!!

void wuGrass::capture(ofxCvColorImage *color, ofxCvGrayscaleImage * grayDiff)
    {

            contour.findContours(*grayDiff, 20, (ofGetWidth()*ofGetHeight())/3, 10, false);	// find holes

            int limitY = contour.blobs[0].boundingRect.y + (contour.blobs[0].boundingRect.height/2);
			grassPoints.clear();

            for(int i=contour.blobs[0].pts.size()-1; i>0; i--) {
                ofPoint p;
                p = contour.blobs[0].pts[i];
                if (p.y < limitY)
                   grassPoints.push_back(p);
            }

//			grassPoints =  contour.blobs[0].pts;
			setFieldFromPoints(grassPoints);
};

void wuGrass::clear(){
    mBlades.clear();
    mBladePoints.clear();
//    grassPoints.clear();
}


