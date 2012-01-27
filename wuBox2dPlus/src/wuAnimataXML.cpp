#include "wuAnimataXML.h"

wuAnimataXML::wuAnimataXML()
{
}

wuAnimataXML::~wuAnimataXML()
{
}

void wuAnimataXML::setup(ofxBox2d * _box2d, string _filename, int _vw, int _vh, vector <wuSkin> * _skins, ofRectangle rect){

	// posiciona l' animació al lloc del blob + gran 
	// posicionem la base on és el blob
	wuHumanoid::setup(_box2d, _vw, _vh);//, rect.x+(rect.width/2), rect.y + rect.height - basedim);

	cout << rect.y + rect.height - basedim << "_";
	XML.loadXML(_filename);
	bCaptured=false;
	old_offX = 0;
	old_offY = 0;

	// recullo el punter al vector d' skins
	setSkin(_skins);

//	for(int i=0; i< skins->size(); i++)
//		cout << i << " " << (*skins)[i].posSkin.x << endl;

	bCaptured=true;
	bFirstTime = true;
	XML.goto0();

}

void wuAnimataXML::setSkin( vector <wuSkin> * _skins)
{
	skins = _skins;
	OrderSkins();
}

void wuAnimataXML::update()
{
	if(bCaptured)
	{
		updateFrame(XML.getNextFrame());
		frame2Skel();
		skelCorrection();

		MakeFBOimage();
		wuHumanoid::update();
	}

}


void wuAnimataXML::MakeFBOimage()
{
	float angle;
	float lineX;
	float lineY;

	ofSetColor(255, 255, 255, 255);

    //  2 body pieces minimum
	if (skel.bDetected && skins->size() > 2) 
	{

		wuEnte::myFBO_begin();

		// draw Head Skin
			lineX = skel.head.x - skel.neck.x;
			lineY = skel.head.y - skel.neck.x;
			angle = -atan2(lineX,lineY);+(PI);

			ofPushMatrix();
			    ofTranslate(skel.head.x*scale.x+framePos.x, skel.head.y*scale.y+framePos.y);
				(*skins)[ord[HEAD]].skin.setAnchorPercent(0.5, 0.5);
				ofRotateZ(ofRadToDeg(angle));
				ofEnableAlphaBlending();
				(*skins)[ord[HEAD]].skin.draw(0, 0);
				ofDisableAlphaBlending();
			ofPopMatrix();


			// draw Torso Skin
			lineX = skel.neck.x - skel.torso.x;
			lineY = skel.neck.y - skel.torso.y;
			angle = -atan2(lineX,lineY)+(PI);

			ofPushMatrix();
			    ofTranslate(skel.neck.x*scale.x+framePos.x, skel.neck.y*scale.y+framePos.y);
				(*skins)[ord[TORSO]].skin.setAnchorPercent(0.5, 0.0);
				ofRotateZ(ofRadToDeg(angle));
				ofEnableAlphaBlending();
				(*skins)[ord[TORSO]].skin.draw(0, 0);
				ofDisableAlphaBlending();
			ofPopMatrix();

			// draw Left Arm Skin
			lineX = skel.Lelbow.x - skel.Lshoulder.x;
			lineY = skel.Lelbow.y - skel.Lshoulder.y;
			angle = - atan2(lineX,lineY)+(PI);

			ofPushMatrix();
				ofEnableAlphaBlending();
			    ofTranslate(modSkel.Lelbow.x*scale.x+framePos.x, modSkel.Lelbow.y*scale.y+framePos.y);
				(*skins)[ord[LEFT_ARM]].skin.setAnchorPercent(0.5, 0.0);
				ofRotateZ(ofRadToDeg(angle));
				(*skins)[ord[LEFT_ARM]].skin.draw(0, 0);
				ofDisableAlphaBlending();
			ofPopMatrix();

			// draw Left Hand Skin
			lineX = skel.Lelbow.x - skel.Lhand.x;
			lineY = skel.Lelbow.y - skel.Lhand.y;
			angle = - atan2(lineX,lineY)+(PI);

			ofPushMatrix();
				ofTranslate(modSkel.Lelbow.x*scale.x+framePos.x, modSkel.Lelbow.y*scale.y+framePos.y);
				(*skins)[ord[LEFT_HAND]].skin.setAnchorPercent(0.5, 0.0);
				ofRotateZ(ofRadToDeg(angle));
				ofEnableAlphaBlending();
				(*skins)[ord[LEFT_HAND]].skin.draw(0, 0);
				ofDisableAlphaBlending();
			ofPopMatrix();

			// draw Left Leg Skin
			lineX = skel.Lhip.x - skel.Lknee.x;
			lineY = skel.Lhip.y - skel.Lknee.y;
			angle = - atan2(lineX,lineY)+(PI);

			ofPushMatrix();
				ofTranslate(skel.Lhip.x*scale.x+framePos.x, skel.Lhip.y*scale.y+framePos.y);
				(*skins)[ord[LEFT_LEG]].skin.setAnchorPercent(0.5, 0.0);
				ofRotateZ(ofRadToDeg(angle));
				ofEnableAlphaBlending();
				(*skins)[ord[LEFT_LEG]].skin.draw(0, 0);
				ofDisableAlphaBlending();
			ofPopMatrix();

			// draw Left Foot Skin
			lineX = skel.Lknee.x - skel.Lfoot.x;
			lineY = skel.Lknee.y - skel.Lfoot.y;
			angle = - atan2(lineX,lineY)+(PI);

			ofPushMatrix();
				ofTranslate(modSkel.Lknee.x*scale.x+framePos.x, modSkel.Lknee.y*scale.y+framePos.y);
				(*skins)[ord[LEFT_FOOT]].skin.setAnchorPercent(0.5, 0.0);
				ofRotateZ(ofRadToDeg(angle));
				ofEnableAlphaBlending();
				(*skins)[ord[LEFT_FOOT]].skin.draw(0, 0);
				ofDisableAlphaBlending();
			ofPopMatrix();

			// draw Right Arm Skin
			lineX = skel.Rshoulder.x - skel.Relbow.x;
			lineY = skel.Rshoulder.y - skel.Relbow.y;
			angle = - atan2(lineX,lineY)+(PI);

			ofPushMatrix();
				ofTranslate(skel.Rshoulder.x*scale.x+framePos.x, skel.Rshoulder.y*scale.y+framePos.y);
				(*skins)[ord[RIGHT_ARM]].skin.setAnchorPercent(0.5, 0.0);
				ofRotateZ(ofRadToDeg(angle));
				ofEnableAlphaBlending();
				(*skins)[ord[RIGHT_ARM]].skin.draw(0, 0);
				ofDisableAlphaBlending();
			ofPopMatrix();

			// draw Right Hand Skin
			lineX = skel.Relbow.x - skel.Rhand.x;
			lineY = skel.Relbow.y - skel.Rhand.y;
			angle = - atan2(lineX,lineY)+(PI);

			ofPushMatrix();
				ofTranslate(modSkel.Relbow.x*scale.x+framePos.x, modSkel.Relbow.y*scale.y+framePos.y);
				(*skins)[ord[RIGHT_HAND]].skin.setAnchorPercent(0.5, 0.0);
				ofRotateZ(ofRadToDeg(angle));
				ofEnableAlphaBlending();
				(*skins)[ord[RIGHT_HAND]].skin.draw(0, 0);
				ofDisableAlphaBlending();
			ofPopMatrix();

			// draw Right Leg Skin
			lineX = skel.Rhip.x - skel.Rknee.x;
			lineY = skel.Rhip.y - skel.Rknee.y;
			angle = - atan2(lineX,lineY)+(PI);

			ofPushMatrix();
				ofTranslate(skel.Rhip.x*scale.x+framePos.x, skel.Rhip.y*scale.y+framePos.y);
				(*skins)[ord[RIGHT_LEG]].skin.setAnchorPercent(0.5, 0.0);
				ofRotateZ(ofRadToDeg(angle));
				ofEnableAlphaBlending();
				(*skins)[ord[RIGHT_LEG]].skin.draw(0, 0);
				ofDisableAlphaBlending();
			ofPopMatrix();

			// draw Right Foot Skin
			lineX = skel.Rknee.x - skel.Rfoot.x;
			lineY = skel.Rknee.y - skel.Rfoot.y;
			angle = - atan2(lineX,lineY)+(PI);

			int ample = (*skins)[ord[RIGHT_FOOT]].skin.getWidth();

			ofPushMatrix();
				ofTranslate(modSkel.Rknee.x*scale.x+framePos.x+ample, modSkel.Rknee.y*scale.y+framePos.y);
				(*skins)[ord[RIGHT_FOOT]].skin.setAnchorPercent(0.5, 0.0);
				ofRotateZ(ofRadToDeg(angle));
				ofEnableAlphaBlending();
				(*skins)[ord[RIGHT_FOOT]].skin.draw(0, 0);
				ofDisableAlphaBlending();
			ofPopMatrix();

			if(skins->size() > 3)
			{
				// draw Hip Skin
				lineX = skel.Lhip.x - skel.Rhip.x;
				lineY = skel.Lhip.y - skel.Rhip.y;
				angle = - atan2(lineX,lineY)+(PI/2);

				ofPushMatrix();
					ofTranslate(((skel.Lhip.x + skel.Rhip.x)*scale.x/2)+framePos.x, skel.Lhip.y*scale.y+framePos.y);
					(*skins)[ord[HIP]].skin.setAnchorPercent(0.5, 0.0);
					ofRotateZ(ofRadToDeg(angle));
					ofEnableAlphaBlending();
					(*skins)[ord[HIP]].skin.draw(0, 0);
					ofDisableAlphaBlending();
				ofPopMatrix();
			}
	
			wuEnte::myFBO_end();
	}

}


void wuAnimataXML::draw(bool bDrawlines, int _offX)
{
	ofSetColor(255, 255, 255);

	if (skel.bDetected && skins->size() > 2) 
	{
		wuEnte::draw_FBO(_offX, 0);
	}
	wuHumanoid::draw(bDrawlines, _offX);
}

void wuAnimataXML::updateFrame(vector<pieceInfo> * _newframe)
{
		frame.clear();

		for(int i=0; i < (*_newframe).size(); i++)
		{
			pieceInfo piece;

			piece.pos = (*_newframe)[i].pos;
			piece.ang = (*_newframe)[i].ang;
			// add piece position to frame
			frame.push_back(piece);
		}
}

void wuAnimataXML::frame2Skel()
{
	skel.head = frame[0].pos;
	skel.neck = frame[1].pos;
	skel.Lshoulder = frame[2].pos;
	skel.Rshoulder = frame[3].pos;
	skel.Lelbow = frame[4].pos;
	skel.Relbow = frame[5].pos;
	skel.Lhand = frame[6].pos;
	skel.Rhand = frame[7].pos;
	skel.torso = frame[8].pos;
	skel.Lhip = frame[9].pos;
	skel.Rhip = frame[10].pos;
	skel.Lknee = frame[11].pos;
	skel.Rknee = frame[12].pos;
	skel.Lfoot = frame[13].pos;
	skel.Rfoot = frame[14].pos;

	skel.bDetected = true;
}

// registra en ord[] els skins segons la pos.x en que van ser capturats (de petit a gran)
// ja que skins[] està ordenat per arees de blob.
void wuAnimataXML::OrderSkins()
{
	float max_X=0;

	for(int j=0; j < skins->size(); j++)
	{
			float min_X_local=vw;
			for(int i=0; i < skins->size(); i++)
			{
				// busca el valor de posició més petit sense comptar les posicions
				// que han sigut assignades fins ara (els majors de min_X)
				if( (*skins)[i].posSkin.x	< min_X_local && (*skins)[i].posSkin.x > max_X)
				{
					min_X_local = (*skins)[i].posSkin.x;
					ord[j] = i;
				}
			}
			max_X = (*skins)[ ord[j] ].posSkin.x;
	}

	for(int i=0; i < 11; i++)
		ord[i] = i;

	switch(skins->size())
	{
		case 3: // head, torso, 1 extremity
			ord[LEFT_LEG]=ord[LEFT_ARM];
			ord[RIGHT_LEG]=ord[LEFT_ARM];
			ord[RIGHT_ARM]=ord[LEFT_ARM];
			ord[LEFT_HAND]=ord[LEFT_ARM];
			ord[RIGHT_HAND]=ord[LEFT_ARM];
			ord[LEFT_FOOT]=ord[LEFT_ARM];
			ord[RIGHT_FOOT]=ord[LEFT_ARM];
			break;
		case 4: // head, torso, 1 extremity, 1 hip
			ord[RIGHT_ARM]=ord[LEFT_ARM];
			ord[RIGHT_LEG]=ord[LEFT_LEG];
			ord[LEFT_HAND]=ord[LEFT_ARM];
			ord[RIGHT_HAND]=ord[LEFT_ARM];
			ord[LEFT_FOOT]=ord[LEFT_LEG];
			ord[RIGHT_FOOT]=ord[LEFT_LEG];
			break;
		case 5: // head, torso, L arm, hip, L leg
			ord[RIGHT_ARM]=ord[LEFT_ARM];
			ord[RIGHT_LEG]=ord[LEFT_LEG];
			ord[LEFT_HAND]=ord[LEFT_ARM];
			ord[RIGHT_HAND]=ord[LEFT_HAND];
			ord[LEFT_FOOT]=ord[LEFT_LEG];
			ord[RIGHT_FOOT]=ord[LEFT_LEG];
			break;
		case 6: // head, torso, L arm, hip, L leg, L hand 
			ord[RIGHT_LEG]=ord[LEFT_LEG];
			ord[RIGHT_ARM]=ord[LEFT_ARM];
			ord[RIGHT_HAND]=ord[LEFT_HAND];
			ord[LEFT_FOOT]=ord[LEFT_LEG];
			ord[RIGHT_FOOT]=ord[LEFT_LEG];
			break;
		case 7: // head, torso, L arm, hip, L leg, L hand, L foot 
			ord[RIGHT_LEG]=ord[LEFT_LEG];
			ord[RIGHT_ARM]=ord[LEFT_ARM];
			ord[RIGHT_HAND]=ord[LEFT_HAND];
			ord[RIGHT_FOOT]=ord[LEFT_FOOT];
			break;
		case 8: // head, torso, L arm, hip, L leg, L,R hand, L foot 
			ord[RIGHT_LEG]=ord[LEFT_LEG];
			ord[RIGHT_ARM]=ord[LEFT_ARM];
			ord[RIGHT_FOOT]=ord[LEFT_FOOT];
			break;
		case 9: // head, torso, L arm, hip, L leg, L,R hand, L,R foot 
			ord[RIGHT_LEG]=ord[LEFT_LEG];
			ord[RIGHT_ARM]=ord[LEFT_ARM];
			break;
		case 11: // all
			break;
	}

	cout << "**********";
	cout << "head " << (*skins)[ord[HEAD]].posSkin.x << endl;
	cout << "torso " << (*skins)[ord[TORSO]].posSkin.x << endl;
	cout << "lharm " << (*skins)[ord[LEFT_ARM]].posSkin.x << endl;

}

void wuAnimataXML::skelCorrection()
{
	if (skel.bDetected && skins->size() > 2) 
	{
		float angUpper;
		float angLower;
		ofPoint ptUpper;
		ofPoint ptLower;
		float radUpper;	
		float radLower;	

		// find left arm angle *******************************************
		ptUpper.x = skel.Lshoulder.x - skel.Lelbow.x;
		ptUpper.y = skel.Lshoulder.y - skel.Lelbow.y;
		angUpper =  atan2(ptUpper.x,ptUpper.y)+(PI);
		radUpper = (*skins)[ord[LEFT_ARM]].skin.getHeight()/scale.y;

		// find left hand angle
		ptLower.x = skel.Lelbow.x - skel.Lhand.x;
		ptLower.y = skel.Lelbow.y - skel.Lhand.y;
		angLower =  atan2(ptLower.x,ptLower.y)+(PI);
		radLower = (*skins)[ord[LEFT_HAND]].skin.getHeight()/scale.y;
	
		// find new left elbow point
		modSkel.Lelbow.x = skel.Lshoulder.x + sin(angUpper)*radUpper;
		modSkel.Lelbow.y = skel.Lshoulder.y + cos(angUpper)*radUpper;
	
		// find new left hand point
		modSkel.Lhand.x = modSkel.Lelbow.x + sin(angLower)*radLower;
		modSkel.Lhand.y = modSkel.Lelbow.y + cos(angLower)*radLower;
		

		// find left leg angle *******************************************
		ptUpper.x = skel.Lhip.x - skel.Lknee.x;
		ptUpper.y = skel.Lhip.y - skel.Lknee.y;
		angUpper =  atan2(ptUpper.x,ptUpper.y)+(PI);
		radUpper = (*skins)[ord[LEFT_LEG]].skin.getHeight()/scale.y;

		// find left foot angle
		ptLower.x = skel.Lknee.x - skel.Lfoot.x;
		ptLower.y = skel.Lknee.y - skel.Lfoot.y;
		angLower =  atan2(ptLower.x,ptLower.y)+(PI);
		radLower = (*skins)[ord[LEFT_FOOT]].skin.getHeight()/scale.y;

		// find new left knee point
		modSkel.Lknee.x = skel.Lhip.x + sin(angUpper)*radUpper;
		modSkel.Lknee.y = skel.Lhip.y + cos(angUpper)*radUpper;

		// find new left foot point
		modSkel.Lfoot.x = modSkel.Lknee.x + sin(angLower)*radLower;
		modSkel.Lfoot.y = modSkel.Lknee.y + cos(angLower)*radLower;


		// find Right arm angle *******************************************
		ptUpper.x = skel.Rshoulder.x - skel.Relbow.x;
		ptUpper.y = skel.Rshoulder.y - skel.Relbow.y;
		angUpper =  atan2(ptUpper.x,ptUpper.y)+(PI);
		radUpper = (*skins)[ord[RIGHT_ARM]].skin.getHeight()/scale.y;

		// find Right Hand angle
		ptLower.x = skel.Relbow.x - skel.Rhand.x;
		ptLower.y = skel.Relbow.y - skel.Rhand.y;
		angLower =  atan2(ptLower.x,ptLower.y)+(PI);
		radLower = (*skins)[ord[RIGHT_HAND]].skin.getHeight()/scale.y;

		// find new right arm point
		modSkel.Relbow.x = skel.Rshoulder.x + sin(angUpper)*radUpper;
		modSkel.Relbow.y = skel.Rshoulder.y + cos(angUpper)*radUpper;

		// find new right hand point
		modSkel.Rhand.x = modSkel.Relbow.x + sin(angLower)*radLower;
		modSkel.Rhand.y = modSkel.Relbow.y + cos(angLower)*radLower;

		// find right leg angle *******************************************
		ptUpper.x = skel.Rhip.x - skel.Rknee.x;
		ptUpper.y = skel.Rhip.y - skel.Rknee.y;
		angUpper =  atan2(ptUpper.x,ptUpper.y)+(PI);
		radUpper = (*skins)[ord[RIGHT_LEG]].skin.getHeight()/scale.y;


		// find Right Foot angle
		ptLower.x = skel.Rknee.x - skel.Rfoot.x;
		ptLower.y = skel.Rknee.y - skel.Rfoot.y;
		angLower =  atan2(ptLower.x,ptLower.y)+(PI);
		radLower = (*skins)[ord[RIGHT_FOOT]].skin.getHeight()/scale.y;

		// find new rigth knee point
		modSkel.Rknee.x = skel.Lhip.x + sin(angUpper)*radUpper;
		modSkel.Rknee.y = skel.Lhip.y + cos(angUpper)*radUpper;

		// find new right foot point
		modSkel.Rfoot.x = modSkel.Rknee.x + sin(angLower)*radLower;
		modSkel.Rfoot.y = modSkel.Rknee.y + cos(angLower)*radLower;

		// ***** defineixo que la base estarà als peus *************
		if (modSkel.Rfoot.y > modSkel.Lfoot.y)
			foot_base_pos.y = modSkel.Rfoot.y*scale.y -basedim;
		else
			foot_base_pos.y = modSkel.Lfoot.y*scale.y -basedim;

//		foot_base_pos.x = ((modSkel.Lfoot.x+modSkel.Rfoot.x)/2*scale);
		foot_base_pos.x = skel.torso.x*scale.x;


	}
}