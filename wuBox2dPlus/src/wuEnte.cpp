#include "wuEnte.h"

wuEnte::wuEnte()
{
}

wuEnte::~wuEnte()
{
}

void wuEnte::setup(ofxBox2d * _box2d, int _vw, int _vh){
    box2d = _box2d;

	initPos.x = 310;
	initPos.y = 9;

    vw = _vw;
    vh = _vh;

//  simpleAmount = 15.0;
   	simpleAmount = 1.0;

	contourAnalysis.setSize(vw, vh);

	grayDiff.clear();
	grayDiff.allocate(vw, vh);

	bTouched = false;

	basedim = 25; // base size

	base.setPhysics(0.01, 0.0, 10.0031);
	base.setup(box2d->getWorld(), initPos.x, initPos.y, basedim, basedim);

	framePos.x = 0;
	framePos.y = 0;
	shapeOff.x = 0;
	shapeOff.y = 0;
	scale.x = scale.y = 1.0;
}


void wuEnte::setContourAmount(int _simpleAmount){
   	simpleAmount = _simpleAmount;
}

void wuEnte::update()
{
	FindShape(&grayDiff);
}

void wuEnte::draw(bool bDrawlines, int _offX)
{
	ofSetColor(255, 255, 255);

	if(bDrawlines && _offX==0)
	{
		// box2dRect base
		base.draw();

		// kinect frame
		ofRect(rect.x, rect.y, rect.width, rect.height);

		ofSetColor(0,255,255);
	    for(int i=0; i<lineStrips.size(); i++)
			lineStrips[i].draw();

	}
}

void wuEnte::FindShape(wuGrayImg * _grayDiff)
{
		    ofPoint p;
			p = base.getPosition();

		    contour.blobs.clear();
			contour.findContours(*_grayDiff, 20, (vw*vh), 10, false);	// find holes

		    for(int i=0; i<lineStrips.size(); i++)
			{
				lineStrips[i].clear();
			}
			lineStrips.clear();

            if(contour.nBlobs > 0){

                contourAnalysis.simplify(contour.blobs[0].pts, simpleCountour, simpleAmount);

				// rectangle al voltant de l' enanito
                rect.x = contour.blobs[0].boundingRect.x;
                rect.y = contour.blobs[0].boundingRect.y;
                rect.width = contour.blobs[0].boundingRect.width;
                rect.height = contour.blobs[0].boundingRect.height;

				if(!bTouched)
				{
					ofxBox2dLine lineStrip;

					for(int j=simpleCountour.size()-1; j>-1; j--) {
						if (simpleCountour[j].y < p.y - basedim/2 -15)
						    lineStrip.addPoint(simpleCountour[j].x+shapeOff.x, simpleCountour[j].y+shapeOff.y);
					}
					lineStrip.setWorld(box2d->getWorld());
					lineStrip.setElasticity(0.);
					lineStrip.createShape();
					lineStrips.push_back(lineStrip);	
				}
				bTouched = false;
 
			}
}

/*void wuEnte::FindShape(wuGrayImg * _grayDiff)
{
		    ofPoint p;
			p = base.getPosition();

		    contour.blobs.clear();
			contour.findContours(*_grayDiff, 20, (vw*vh), 10, false);	// find holes

		    for(int i=0; i<lineStrips.size(); i++)
			{
				lineStrips[i].clear();
			}
			lineStrips.clear();

            if(contour.nBlobs > 0){

                contourAnalysis.simplify(contour.blobs[0].pts, simpleCountour, simpleAmount);

				cout << rectX << "_r_";
				// rectangle al voltant de l' enanito
                rectX = contour.blobs[0].boundingRect.x*scaleX;
                rectY = contour.blobs[0].boundingRect.y*scaleY;
                rectW = contour.blobs[0].boundingRect.width*scaleX;
                rectH = contour.blobs[0].boundingRect.height*scaleY;

				if(!bTouched)
				{
					ofxBox2dLine lineStrip;

					for(int j=simpleCountour.size()-1; j>-1; j--) {
						if (simpleCountour[j].y*scaleX+kinFrameY < p.y - basedim/2 -15)
						    lineStrip.addPoint(simpleCountour[j].x*scaleX+kinFrameX, simpleCountour[j].y*scaleY+kinFrameY);
					}
					lineStrip.setWorld(box2d->getWorld());
					lineStrip.setElasticity(0.);
					lineStrip.createShape();
					lineStrips.push_back(lineStrip);	
				}
				bTouched = false;
 
			}
}
*/
bool wuEnte::isTouched(int _x,int _y)
{
	if( (_x > rect.x) && (_x < rect.x+rect.width) && (_y > rect.y) && (_y < rect.y+rect.height) ) 
		bTouched = true;
	else
		bTouched = false;

	return bTouched;
}
void wuEnte::Touch(int _x,int _y, int forceX, int forceY)
{
	ofPoint p;
	p = base.getPosition();

	if( (_x > rect.x) && (_x < rect.x+rect.width) && (_y > rect.y) && (_y < rect.y+rect.height) ) 
	{
		if(forceX > 0)
		{
			if( (_x > rect.x) && (_x < rect.x+rect.width/2)) 
				base.addForce(ofPoint(rect.x,p.y), ofPoint(forceX,0));
			if( (_x > rect.x+rect.width/2) && (_x < rect.x+rect.width)) 
				base.addForce(ofPoint(rect.x+rect.width,p.y), ofPoint(0-forceX,0));
		}
		if(forceY > 0)
		{
			if( (_y > rect.y) && (_y < rect.y+rect.height/2) ) 
				base.addForce(ofPoint(p.x,rect.y), ofPoint(0,0-forceY));
			if( (_y > rect.y+rect.height/2) && (_y < rect.y+rect.height) ) 
				base.addForce(ofPoint(p.x,rect.y+rect.height), ofPoint(0,forceY));
		}
	}
}
void wuEnte::setPosition(int _x,int _y)
{
		base.moveTo(_x,_y);
}
ofPoint wuEnte::getPosition()
{
	return base.getPosition();
}

