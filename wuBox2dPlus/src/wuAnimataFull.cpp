#include "crAnimataFull.h"

crAnimataFull::crAnimataFull()
{
}

crAnimataFull::~crAnimataFull()
{
}

void crAnimataFull::setup(ofxBox2d * _box2d, string _filename, int _Xini, int _Yini){

	XML.loadXML(_filename);
	super::setup(_box2d, _Xini, _Yini);
	bKinectSource=false;
}

void crAnimataFull::setup(ofxBox2d * _box2d, crKinectSkel * _kinSkel, int _Xini, int _Yini)
{
	kinSkel = _kinSkel;
	kinSkel->setup();
	bKinectSource = true;
}

void crAnimataFull::update()
{
	if(bKinectSource)
	{
//		cout << "0 ";
		super::setSkel(kinSkel->getSkeleton());
//		cout << "1 ";
	}
	else
		super::setSkel(XML.getSkeleton());

	super::update();
//	cout << "3 ";
}

