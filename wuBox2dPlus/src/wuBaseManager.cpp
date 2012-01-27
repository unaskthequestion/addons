#include "wuBaseManager.h"

wuBaseManager::wuBaseManager()
{

}

wuBaseManager::~wuBaseManager()
{
}

void wuBaseManager::setup(int _vw, int _vh){
    vw = _vw;
    vh = _vh;

	color.allocate(vw, vh);
	bgColor.allocate(vw, vh);
	gray.allocate(vw, vh);
	bgGrayImg.allocate(vw, vh);
	grayDiff.allocate(vw, vh);

	minBlobSize = 20;
	maxBlobs = 20;
	threshold = 11;
}

void wuBaseManager::setMaxBlobs(int _maxBlobs)
{
	maxBlobs = _maxBlobs;
}

void wuBaseManager::setMinBlobSize(int _minBlobSize)
{
	minBlobSize = _minBlobSize;
}

void wuBaseManager::setThreshold(int _thres)
{
	threshold = _thres;
}

void wuBaseManager::capture(ofImage *currImg, ofImage *bgImg)
{

    color.setFromPixels(currImg->getPixels(), vw,vh);
    gray = color;
    bgColor.setFromPixels(bgImg->getPixels(), vw,vh);
    bgGrayImg = bgColor;

	// take the abs value of the difference between background and incoming and then threshold:
	grayDiff.absDiff(gray, bgGrayImg);
	grayDiff.threshold(threshold);
	grayDiff.blur(5);

	contour.blobs.clear();
    contour.findContours(grayDiff, minBlobSize, (vw*vh)/2, 10, false);	// find holes

    for (int i = 0; i < contour.nBlobs && i < maxBlobs ; i++)
	{
		ofRectangle rect;

		rect.x = contour.blobs[i].boundingRect.x;
		rect.y = contour.blobs[i].boundingRect.y;
		rect.width = contour.blobs[i].boundingRect.width;
		rect.height = contour.blobs[i].boundingRect.height;

		wuImagePlus _skin;
		_skin.crop(color.getPixels(), grayDiff.getPixels(), vw, vh, rect);
		
		addBitxo(&_skin, rect, &(contour.blobs[i]));

	}

}

void wuBaseManager::addBitxo(ofImage *_skin, ofRectangle rect, ofxCvBlob *blob)
{
}
