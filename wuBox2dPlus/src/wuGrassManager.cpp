#include "wuGrassManager.h"

wuGrassManager::wuGrassManager()
{

}

wuGrassManager::~wuGrassManager()
{
}

void wuGrassManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob)
{
	wuBase2dShapeManager::addBitxo(_skin, rect, blob);

    int limitY = contour.blobs[0].boundingRect.y + (contour.blobs[0].boundingRect.height/2);
	
	vector<ofPoint>	grassPoints;

    for(int i=blob->pts.size()-1; i>0; i--) {
        ofPoint p;
        p = blob->pts[i];
        if (p.y < limitY)
             grassPoints.push_back(p);
     }

	wuGrass grass;
	grass.setup(box2d, grassPoints);
	grasses.push_back(grass);

//	wuMassive massive;
//	massive.setup(box2d, _skin, rect, tri.triangles, lin_damp, restitution, friction);
//	massives.push_back(massive);
}

void wuGrassManager::update()
{
        for (int i = 0; i < grasses.size(); i++)
            grasses[i].update();	
}

void wuGrassManager::draw(int x, int y)
{
        for (int i = 0; i < grasses.size(); i++)
//            grasses[i].draw(bDrawlines, offX);	
            grasses[i].draw(x,y);	
}

void wuGrassManager::clear()
{
    for (int i = 0; i < grasses.size(); i++)
		grasses[i].clear();
	grasses.clear();
}

void wuGrassManager::mouseMoved(int x, int y ) {
    for (int i = 0; i < grasses.size(); i++)
		grasses[i].mouseMoved(x,y);

}
