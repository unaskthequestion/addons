#include "wuMassive.h"

wuMassive::wuMassive()
{

}

wuMassive::~wuMassive()
{
}

void wuMassive::setup(ofxBox2d * _box2d, ofImage *_skin, ofRectangle rect, vector<ofxTriangleData> triangles, float _lin_damp, float _restitution, float _friction)
{
	lin_damp=_lin_damp;
	restitution = _restitution;
	friction = _friction;
	ang_damp=0.25;

	wuBase2d::setup(_box2d, rect);
	wuBaseSkin::setSkin(_skin, rect);

	// make 2D object
	b2BodyDef* bodyDef = new b2BodyDef();
	bodyDef->position.Set(0, 0);
	bodyDef->linearDamping = lin_damp;
	bodyDef->angularDamping = ang_damp;

	body = box2d->getWorld()->CreateBody(bodyDef);
	makeComplexBody(body, triangles);
}

//http://www.psyked.co.uk/box2d/simple-box2d-custom-polygon-creation.htm
void wuMassive::makeComplexBody(b2Body* bodyin, vector<ofxTriangleData> triangles) {

	for (int i = 0; i < triangles.size(); i++) 
	{
		b2PolygonDef* shapeDef = new b2PolygonDef();
		shapeDef->density = 4.1;
		shapeDef->restitution = restitution;
		shapeDef->friction = friction;
		shapeDef->vertexCount = 3;

		shapeDef->vertices[0].Set(triangles[i].a.x/OFX_BOX2D_SCALE, triangles[i].a.y/OFX_BOX2D_SCALE);
		shapeDef->vertices[1].Set(triangles[i].b.x/OFX_BOX2D_SCALE, triangles[i].b.y/OFX_BOX2D_SCALE);
		shapeDef->vertices[2].Set(triangles[i].c.x/OFX_BOX2D_SCALE, triangles[i].c.y/OFX_BOX2D_SCALE);

		bodyin->CreateShape(shapeDef);
	}

    bodyin->SetMassFromShapes();
}

void wuMassive::update()
{
    b2Vec2 v_pos = body->GetWorldCenter();
    float32 ang =body->GetAngle();

	ofPoint _pos;

	_pos.x = v_pos.x*OFX_BOX2D_SCALE;
	_pos.y = v_pos.y*OFX_BOX2D_SCALE;
			
	posSkin = _pos; 
	angSkin = ang;

}

void wuMassive::clear()
{
// carregar-se els shapes fa que peti
/*	b2Shape* s = body->GetShapeList();

	for (int j = 0; j < shapeCount-1; j++) {
		b2Shape* next = s->GetNext();
		s = next;
		body->DestroyShape(s);
	}*/
//	box2d->world->DestroyBody(body);

}

void wuMassive::touch(int _x,int _y, int forceX, int forceY)
{
	ofPoint tam;
	ofPoint p;

	p = getPosition();

	if ((_x > p.x - width/2) && (_x < p.x + width/2) && (_y > p.y - height/2) && (_y < p.y + height/2))
	{	
		if(forceX>0)
		{
			if ((_x > p.x - width/2) && (_x < p.x))
				body->ApplyForce(b2Vec2((p.x - width/2)/OFX_BOX2D_SCALE, p.y/OFX_BOX2D_SCALE), b2Vec2(forceX, 0));
			if ((_x > p.x) && (_x < p.x + width/2))
				body->ApplyForce(b2Vec2((p.x + width/2)/OFX_BOX2D_SCALE, p.y/OFX_BOX2D_SCALE), b2Vec2(0-forceX, 0));
		}
		if(forceY>0)
		{
			if ((_y > p.y - height/2) && (_y < p.y))
				body->ApplyForce(b2Vec2(p.x/OFX_BOX2D_SCALE, (p.y - height/2)/OFX_BOX2D_SCALE), b2Vec2(0, 0-forceY));
			if ((_y > p.y) && (_y < p.y + height/2))
				body->ApplyForce(b2Vec2(p.x/OFX_BOX2D_SCALE, (p.y + height/2)/OFX_BOX2D_SCALE), b2Vec2(0, forceY));
		}
	}	
}

