//
//  wuTeatrillu.h
//  teatrilluwu
//
//  Created by roger on 16/01/2012.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#pragma once

#include "ofMain.h"
#include "ofxVectorMath.h"
#include "ofxBox2d.h"
#include "wuNuvolManager.h"
#include "wuSkinManager.h"
#include "wuPapallonaManager.h"
#include "wuSolidCircleManager.h"
#include "wuForegroundSkinManager.h"
#include "wuSolidShapeManager.h"
#include "wuMassiveManager.h"
#include "wuMarManager.h"
//#include "wuMovieVec.h"
#include "wuBocataManager.h"
#include "wuPlatformManager.h"
#include "wuSolidRectManager.h"
#include "wuSkinManager.h"
#include "wuBlobInspector.h"

//#define _USE_KINECT // uncomment this to use kinect

#ifdef _USEKINECT
#include "wuAnimataKinectManager.h"
#include "wuKinectSkel.h"
#include "wuAnimalXMLManager.h"
#include "wuEnanito.h"
#endif