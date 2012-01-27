#include "wuSkin.h"

wuSkin::wuSkin()
{

}

wuSkin::~wuSkin()
{
}

void wuSkin::setup(ofImage *_skin, ofRectangle rect)
{
	wuBaseSkin::setSkin(_skin, rect);
}
