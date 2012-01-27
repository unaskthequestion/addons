#ifndef wu_KINECTSKEL_H
#define wu_KINECTSKEL_H

#pragma once
#include "ofMain.h"
#include "ofxOpenNI.h"
#include "wuImagePlus.h"
#include "skelstruct.h"

class wuKinectSkel
{
    public:
        wuKinectSkel();
        ~wuKinectSkel();

        void setup();
        virtual void update();
		virtual bool skeletonDetected();
		void draw(bool bDrawlines=false);
		Skeleton getSkeleton();
		unsigned char * getPixelsUsers();
		unsigned char * getPixelsImage();
		unsigned char * getPixelsUsersImage();
		bool isSkeletonian();

		void	setupRecording(string _filename = "");

		// kinect generators
		ofxOpenNIContext	recordContext;
		ofxDepthGenerator	recordDepth;
		ofxImageGenerator	recordImage; 
		ofxUserGenerator	recordUser;
		
        // ofImage skin
        wuImagePlus skin;
		ofImage	allUserMasks, user1Mask, user2Mask;

		Skeleton skel;
		bool bSkeletonian;

		ofxCvGrayscaleImage 	grayDiff;

		int vw, vh;
};
#endif

