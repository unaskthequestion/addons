#include "wuKinectSkel.h"

wuKinectSkel::wuKinectSkel()
{
}

wuKinectSkel::~wuKinectSkel()
{
}

void wuKinectSkel::setup(){

	setupRecording();
	bSkeletonian = false;

}

void wuKinectSkel::setupRecording(string _filename) {
		
	recordContext.setup();	// all nodes created by code -> NOT using the xml config file at all
	recordDepth.setup(&recordContext);
	recordImage.setup(&recordContext);
	recordUser.setup(&recordContext);
	recordUser.setUseMaskPixels(true);
	recordUser.setUseCloudPoints(false);
	recordContext.toggleRegisterViewport();
	recordContext.toggleMirror();
}

void wuKinectSkel::update()
{
	// update all nodes
	recordContext.update();
	recordDepth.update();
	recordImage.update();
		
	// update tracking/recording nodes
	recordUser.update();
		
	// getting pixels from user gen
	allUserMasks.setFromPixels(recordUser.getUserPixels(), recordUser.getWidth(), recordUser.getHeight(), OF_IMAGE_GRAYSCALE);
//	user1Mask.setFromPixels(recordUser.getUserPixels(1), recordUser.getWidth(), recordUser.getHeight(), OF_IMAGE_GRAYSCALE);

	skeletonDetected();


}

void wuKinectSkel::draw(bool bDrawlines)
{
	ofSetColor(255, 255, 255);

	if(bDrawlines)
	{
		// SKELETON			
		recordUser.draw();
	}
}


bool wuKinectSkel::skeletonDetected()
{
	bool bDetected;

	ofxTrackedUser* tracked_user;
	tracked_user = recordUser.getTrackedUser(1);

	skel.Lhand.x = tracked_user->left_lower_arm.position[1].X;
	skel.Lhand.y = tracked_user->left_lower_arm.position[1].Y;
	skel.Lhand.z = tracked_user->left_lower_arm.position[1].Z;
	skel.Rhand.x = tracked_user->right_lower_arm.position[1].X;
	skel.Rhand.y = tracked_user->right_lower_arm.position[1].Y;
	skel.Rhand.z = tracked_user->right_lower_arm.position[1].Z;

	skel.Lelbow.x = tracked_user->left_lower_arm.position[0].X;
	skel.Lelbow.y = tracked_user->left_lower_arm.position[0].Y;
	skel.Lelbow.z = tracked_user->left_lower_arm.position[0].Z;
	skel.Relbow.x = tracked_user->right_lower_arm.position[0].X;
	skel.Relbow.y = tracked_user->right_lower_arm.position[0].Y;
	skel.Relbow.z = tracked_user->right_lower_arm.position[0].Z;

	skel.Rshoulder.x = tracked_user->right_upper_arm.position[0].X;
	skel.Rshoulder.y = tracked_user->right_upper_arm.position[0].Y;
	skel.Rshoulder.z = tracked_user->right_upper_arm.position[0].Z;
	skel.Lshoulder.x = tracked_user->left_upper_arm.position[0].X;
	skel.Lshoulder.y = tracked_user->left_upper_arm.position[0].Y;
	skel.Lshoulder.z = tracked_user->left_upper_arm.position[0].Z;

	skel.neck.x = tracked_user->neck.position[1].X;
	skel.neck.y = tracked_user->neck.position[1].Y;
	skel.neck.z = tracked_user->neck.position[1].Z;

	skel.head.x = tracked_user->neck.position[0].X;
	skel.head.y = tracked_user->neck.position[0].Y;
	skel.head.z = tracked_user->neck.position[0].Z;

	skel.Lknee.x = tracked_user->left_lower_leg.position[0].X;
	skel.Lknee.y = tracked_user->left_lower_leg.position[0].Y;
	skel.Lknee.z = tracked_user->left_lower_leg.position[0].Z;
	skel.Rknee.x = tracked_user->right_lower_leg.position[0].X;
	skel.Rknee.y = tracked_user->right_lower_leg.position[0].Y;
	skel.Rknee.z = tracked_user->right_lower_leg.position[0].Z;

	skel.Lfoot.x = tracked_user->left_lower_leg.position[1].X;
	skel.Lfoot.y = tracked_user->left_lower_leg.position[1].Y;
	skel.Lfoot.z = tracked_user->left_lower_leg.position[1].Z;
	skel.Rfoot.x = tracked_user->right_lower_leg.position[1].X;
	skel.Rfoot.y = tracked_user->right_lower_leg.position[1].Y;
	skel.Rfoot.z = tracked_user->right_lower_leg.position[1].Z;

	skel.Lhip.x = tracked_user->left_lower_torso.position[1].X;
	skel.Lhip.y = tracked_user->left_lower_torso.position[1].Y;
	skel.Lhip.z = tracked_user->left_lower_torso.position[1].Z;
	skel.Rhip.x = tracked_user->right_lower_torso.position[1].X;
	skel.Rhip.y = tracked_user->right_lower_torso.position[1].Y;
	skel.Rhip.z = tracked_user->right_lower_torso.position[1].Z;

	skel.torso.x = tracked_user->right_lower_torso.position[0].X;
	skel.torso.y = tracked_user->right_lower_torso.position[0].Y;
	skel.torso.z = tracked_user->right_lower_torso.position[0].Z;

	if ( tracked_user->neck.found || tracked_user->left_lower_torso.found ||  tracked_user->left_lower_arm.found || tracked_user->left_lower_leg.found)
		skel.bDetected = true;
	else
		skel.bDetected = false;

	return skel.bDetected;
}
Skeleton wuKinectSkel::getSkeleton()
{
	return skel;
}

unsigned char * wuKinectSkel::getPixelsImage()
{
	return recordImage.getPixels();
}

unsigned char * wuKinectSkel::getPixelsUsers()
{
	return allUserMasks.getPixels();
}

unsigned char * wuKinectSkel::getPixelsUsersImage()
{

	skin.crop(recordImage.getPixels(), recordUser.getUserPixels(), 640, 480);
	return skin.getPixels();
}

bool wuKinectSkel::isSkeletonian()
{
	return bSkeletonian;
}