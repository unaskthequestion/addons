#include "wuAnimal.h"

wuAnimal::wuAnimal()
{
}

wuAnimal::~wuAnimal()
{
}

void wuAnimal::setup(ofxBox2d * _box2d, string _filename, int _vw, int _vh, vector <wuSkin> * _skins, ofRectangle rect){

	// posiciona l' animació al lloc del blob + gran 
	// posicionem la base on és el blob
	wuEnte::setup(_box2d, rect.x+(rect.width/2), rect.y + rect.height - basedim);

	myFBO.allocate(_vw, _vh);
	myFBO.clear(0, 0, 0, 0);
	XML.loadXML(_filename);
	bCaptured=false;
	old_offX = 0;
	old_offY = 0;

	// recullo el punter al vector d' skins
	skins = _skins;

	bCaptured=true;
	bFirstTime = true;
	XML.goto0();

}

void wuAnimal::setSkin( vector <wuSkin> * _skins)
{
	skins = _skins;
}

void wuAnimal::update()
{
	if(bCaptured)
	{
		updateFrame(XML.getNextFrame());
		MakeFBOimage();
		wuEnte::update(); // findshape

		if(contour.nBlobs > 0)
		{
			int posX = contour.blobs[0].centroid.x;
			int posY = contour.blobs[0].boundingRect.y;
			int posH = contour.blobs[0].boundingRect.height;

			// posició del blob dins el frame del movie
			offsetX = posX;//*scaleW;
			offsetY = posY + posH - basedim;//*scaleH;
		}


		if(bFirstTime)
		{	
			old_offX = offsetX;
			old_offY = offsetY;
			bFirstTime = false;
		}
		checkMotion();

	}

}


void wuAnimal::MakeFBOimage()
{
	ofSetColor(255, 255, 255, 255);
	ofPoint pos;
	float ang;

	if (skins->size() > 0) 
	{

		myFBO.clear(0, 0, 0, 0);

		myFBO.begin();
		glClearColor(0, 0, 0, 0);

		for(int i=0; i < skins->size(); i++)
		{
			ang = frame[i].ang;
			pos = frame[i].pos;

			// draw Skin at position
			ofPushMatrix();
			    ofTranslate(pos.x, pos.y);
				(*skins)[i].skin.setAnchorPercent(0.5, 0.5);
				ofRotateZ(ofRadToDeg(ang));
				ofEnableAlphaBlending();
				(*skins)[i].skin.draw(0, 0);
				ofDisableAlphaBlending();
			ofPopMatrix();
		}
		myFBO.end();

		grayDiff.setFromAlphaPixels((unsigned char *)myFBO.getPixels(), vw, vh, true);
		grayDiff.blur(5);
	}
}


void wuAnimal::draw(bool bDrawlines, int _offX)
{
	ofSetColor(255, 255, 255);


	if (bCaptured && skins->size() > 0) 
	{
		ofEnableAlphaBlending();
		ofSetColor(255, 255, 255);
		myFBO.draw(_offX+framePos.x,framePos.y);
		ofDisableAlphaBlending();

//		base.draw();

//		ofSetColor(0,255,255);
//	    for(int i=0; i<lineStrips.size(); i++)
//			lineStrips[i].draw();
	}
	wuEnte::draw(bDrawlines, _offX);
}

void wuAnimal::updateFrame(vector<pieceInfo> * _newframe)
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

void wuAnimal::checkMotion()
{

    ofPoint p;
	p = base.getPosition();

    base.moveTo(p.x+(offsetX-old_offX), p.y+(offsetY-old_offY));

    old_offX = offsetX;
    old_offY = offsetY;

	// posició del frame del movie dins l'screen de l' aplicació
	framePos.x = p.x-offsetX;
	framePos.y = p.y-offsetY;

	if (p.y > vh-5)
		base.moveTo(p.x, vh-5);

}
