#include "wuNuvol.h"

wuNuvol::wuNuvol()
{

}

wuNuvol::~wuNuvol()
{
}


void wuNuvol::set2d(ofxBox2d * _box2d, ofRectangle rect)
{
	wuBase2d::setup(_box2d, rect);

	// base rectangle
	base.setPhysics(0.01, 0.00953, 10.0031);
	base.setup(box2d->getWorld(), rect.x+rect.width/2, rect.y+rect.height/2, rect.width/2, rect.height/4);
	base.body->SetFixedRotation(true);

	// hook rectangle
	ancora.setPhysics(0.0, 0.00953, 10.0031);
	ancora.setup(box2d->getWorld(), rect.x+rect.width/2-15, 10, 15, 15);
	b2FilterData filterData;
	filterData.maskBits		= 0x0004;			// read more on filtering under fixtures, http://www.box2d.org/manual.html#_Toc258082972
	ancora.setFilterData( filterData );

	// joint
	joint.setWorld(box2d->getWorld());
	joint.addJoint(base.body, ancora.body, 0.7, 0.01);
				
	// rain
	rain.setup(box2d, rect.width);

}

void wuNuvol::setup(ofxBox2d * _box2d, ofImage *_skin, ofRectangle rect)
{
	wuBaseSkin::setSkin(_skin, rect);
	set2d(_box2d, rect);
}

void wuNuvol::setup(ofxBox2d * _box2d, ofRectangle rect)
{
	set2d(_box2d, rect);
}

void wuNuvol::draw(bool bDrawlines, int offX)
{
	wuBaseSkin::draw(offX);

	// draw rain
	rain.draw(offX);

	if(bDrawlines && offX==0)
	{
         base.draw();
         ancora.draw();
	}		
}

void wuNuvol::update()
{
    ofPoint base_pos_tmp;
    ofPoint anc_pos_tmp;

	base_pos_tmp = base.getPosition();
	anc_pos_tmp = ancora.getPosition();
	ancora.moveTo((base_pos_tmp.x + 29*anc_pos_tmp.x)/30, anc_pos_tmp.y);

	rain.update(base_pos_tmp.x, base_pos_tmp.y);

	// l' skin es mou amb la base
	posSkin = base.getPosition();

}

void wuNuvol::startRain()
{
	rain.startRain();
}
void wuNuvol::stopRain()
{
	rain.stopRain();
}
void wuNuvol::clear()
{
	rain.stopRain();

	box2d->world->DestroyJoint(joint.joint);
	box2d->world->DestroyBody(base.body);
	box2d->world->DestroyBody(ancora.body);
}

void wuNuvol::setPosition(int _x,int _y)
{
	base.moveTo(_x,_y);
}

void wuNuvol::touch(int _x,int _y, int forceX, int forceY)
{
	ofPoint p;
 
	p = base.getPosition();

	if ((_x > p.x - width/2) && (_x < p.x + width/2) && (_y > p.y - height/2) && (_y < p.y + height/2))
	{
		if(forceX>0)
		{
			if ((_x > p.x - width/2) && (_x < p.x))
				base.addForce(ofPoint(p.x - width/2,p.y), ofPoint(forceX,0));
			if ((_x > p.x) && (_x < p.x + width/2) )
				base.addForce(ofPoint(p.x + width/2,p.y), ofPoint(0-forceX,0));
		}
		if(forceY>0)
		{
			if ((_y > p.y - height/2) && (_y < p.y))
				base.addForce(ofPoint(p.x,p.y - height/2), ofPoint(0,0-forceY));
			if ((_y > p.y) && (_y < p.y + height/2))
				base.addForce(ofPoint(p.x,p.y + height/2), ofPoint(0,forceY));
		}
	}
	
}
void wuNuvol::drag(int _x,int _y)
{
	ofPoint p;
 
	p = base.getPosition();

	if ((_x > p.x - width/2) && (_x < p.x + width/2) && (_y > p.y - height/2) && (_y < p.y + height/2))
		setPosition(_x, _y);
}