#include "wuBlobInspector.h"

wuBlobInspector::wuBlobInspector()
{
}

wuBlobInspector::~wuBlobInspector()
{
}

void wuBlobInspector::draw(bool bDrawlines, int offX)
{
	if(bDrawlines)
	{
		ofSetColor(255,0,0);
		for (int i = 0; i < contour.nBlobs; i++){
			contour.blobs[i].draw(offX,0);
		}
	}
}

