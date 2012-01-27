#include "wuSolidRect.h"


wuSolidRect::wuSolidRect()
{

}

wuSolidRect::~wuSolidRect()
{
//    delete grayImage;
}

void wuSolidRect::setImg(ofImage * _img)
{
			img = _img;
			isDead = false;
};

void wuSolidRect::setDim(float _w, float _h)
{
		w = _w;
		h = _h;
};

void wuSolidRect::update()
{
};

void wuSolidRect::draw(int offX) {
		
		if(dead) return;
		
		//wow this is a pain
		b2Shape* s = body->GetShapeList();
		const b2XForm& xf = body->GetXForm();
		b2PolygonShape* poly = (b2PolygonShape*)s;
		int count = poly->GetVertexCount();
		const b2Vec2* localVertices = poly->GetVertices();
		b2Assert(count <= b2_maxPolygonVertices);
		b2Vec2 verts[b2_maxPolygonVertices];
		for(int32 i=0; i<count; ++i) {
			verts[i] = b2Mul(xf, localVertices[i]);
		}

		float lineX = verts[1].x*OFX_BOX2D_SCALE - verts[0].x*OFX_BOX2D_SCALE;
		float lineY = verts[1].y*OFX_BOX2D_SCALE - verts[0].y*OFX_BOX2D_SCALE;
		float ang = -atan2(lineX,lineY)+(PI/2);

		ofSetColor(255, 255, 255);
        ofPushMatrix();
            ofTranslate(getPosition().x+offX, getPosition().y);
            img->setAnchorPercent(0.5, 0.5);
            ofRotateZ(ofRadToDeg(ang));
            ofEnableAlphaBlending();
			img->draw(0, 0, 2*w, 2*h);
            ofDisableAlphaBlending();
        ofPopMatrix();

		if(getPosition().y > 500 || getPosition().x > 700 || getPosition().x < 0)
			isDead = true;
}

void wuSolidRect::setPosition(int _x, int _y)
{
		moveTo(_x,_y);
}

void wuSolidRect::touch(int _x,int _y, int forceX, int forceY)
{
		ofPoint pos;
		
        pos = getPosition();

		if( (_x > pos.x-w) && (_x < pos.x+w) && (_y > pos.y-h) && (_y < pos.y+h) ) 
		{
			if(forceX>0)
			{
				if( (_x > pos.x-w) && (_x < pos.x)) 
					this->addForce(ofPoint(pos.x-w,pos.y), ofPoint(forceX,0));
				if( (_x > pos.x) && (_x < pos.x+w)) 
					this->addForce(ofPoint(pos.x+w,pos.y), ofPoint(0-forceX,0));
			}
			if(forceY>0)
			{
				if( (_y > pos.y-h) && (_y < pos.y) ) 
					this->addForce(ofPoint(pos.x,pos.y-h), ofPoint(0,0-forceY));
				if( (_y > pos.y) && (_y < pos.y+h) ) 
					this->addForce(ofPoint(pos.x,pos.y+h), ofPoint(0,forceY));
			}
		}
}

void wuSolidRect::drag(int _x,int _y)
{
		ofPoint pos;
		
        pos = getPosition();

		if( (_x > pos.x-w) && (_x < pos.x+w) && (_y > pos.y-h) && (_y < pos.y+h) ) 
			setPosition(_x,_y);
}
