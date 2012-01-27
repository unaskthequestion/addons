#include "wuGrayImg.h"

wuGrayImg::wuGrayImg() {
//    init();
}

void wuGrayImg::isolateColor(ofxCvColorImage *videoColorCvImage, int hue, int sat, int val, int hueRange, int satRange, int valRange){

       // SET
   		ofxCvColorImage			videoColorHSVCvImage;
		ofxCvGrayscaleImage		videoGrayscaleHueImage;
		ofxCvGrayscaleImage		videoGrayscaleSatImage;
		ofxCvGrayscaleImage		videoGrayscaleBriImage;
		ofxCvGrayscaleImage		videoGrayOrig;

        int vw = videoColorCvImage->getWidth();
        int vh = videoColorCvImage->getHeight();

        videoColorHSVCvImage.allocate(vw, vh);
        videoGrayscaleHueImage.allocate(vw, vh);
        videoGrayscaleSatImage.allocate(vw, vh);
        videoGrayscaleBriImage.allocate(vw, vh);
        videoGrayOrig.allocate(vw, vh);

        videoGrayOrig = *videoColorCvImage;

		videoColorHSVCvImage = *videoColorCvImage;
		videoColorHSVCvImage.convertRgbToHsv();

		videoColorHSVCvImage.convertToGrayscalePlanarImages(videoGrayscaleHueImage, videoGrayscaleSatImage, videoGrayscaleBriImage);

		videoGrayscaleHueImage.flagImageChanged();		// this is fixing a bug in OF 0.06
		videoGrayscaleSatImage.flagImageChanged();
		videoGrayscaleBriImage.flagImageChanged();

		unsigned char * colorHsvPixels = videoColorHSVCvImage.getPixels();
		unsigned char * grayOrigPixels = videoGrayOrig.getPixels();

		unsigned char * grayPixels = NULL;
		grayPixels = new unsigned char[vw * vh];

		for (int i = 0; i < vw*vh; i++){

				// since hue is cyclical:
				int hueDiff = colorHsvPixels[i*3] - hue;
				if (hueDiff < -127) hueDiff += 255;
				if (hueDiff > 127) hueDiff -= 255;

				if ( (fabs((float)hueDiff) < hueRange) &&
					(colorHsvPixels[i*3+1] > (sat - satRange) && colorHsvPixels[i*3+1] < (sat + satRange)) &&
					(colorHsvPixels[i*3+2] > (val - valRange) && colorHsvPixels[i*3+2] < (val + valRange))){

					grayPixels[i] = 0;

				} else {

					grayPixels[i] = grayOrigPixels[i];
				}

		}
		this->setFromPixels(grayPixels, vw, vh);

		delete [] grayPixels;
}

// mescla amb un altre grayImage - blac+blanc=blanc negre+blanc=blanc
void wuGrayImg::mix(ofxCvGrayscaleImage *grayInput, bool invert){
        int vw = grayInput->getWidth();
        int vh = grayInput->getHeight();

//		cvAdd(grayInput->getCvImage(),this->getCvImage(),
		unsigned char * grayInputPixels = grayInput->getPixels();
		unsigned char * grayOrigPixels = this->getPixels();

		unsigned char * grayPixels = NULL;
		grayPixels = new unsigned char[vw * vh];

		for (int i = 0; i < vw*vh; i++){
			if (grayInputPixels[i]>100)
				grayPixels[i] = 255;
			else
				grayPixels[i]=grayOrigPixels[i];
		}

		this->setFromPixels(grayPixels, vw, vh);

		delete [] grayPixels;

}

	// Crea un grayImage amb un cercle negre i fons blanc
void wuGrayImg::set_antiTocata(int centreX, int centreY, int radi, int vw, int vh, bool invert){

		unsigned char * grayPixels = NULL;
		grayPixels = new unsigned char[vw * vh];

		for (int i = 0; i < vw; i++){
			for (int j = 0; j < vh; j++){
			
				if(invert)
				{
					if((i-centreX)*(i-centreX) + (j-centreY)*(j-centreY) > radi*radi || j< centreY || (i-centreX)*(i-centreX) + (j-centreY)*(j-centreY) < 125)
						grayPixels[(j*vw)+i] = 0;
					else
						grayPixels[(j*vw)+i] = 255;
				}else{
					if((i-centreX)*(i-centreX) + (j-centreY)*(j-centreY) > radi*radi || j< centreY || (i-centreX)*(i-centreX) + (j-centreY)*(j-centreY) < 125)
						grayPixels[(j*vw)+i] = 255;
					else
						grayPixels[(j*vw)+i] = 0;
				}
			}
		}

		this->setFromPixels(grayPixels, vw, vh);

		delete [] grayPixels;
}

void  wuGrayImg::setFromAlphaPixels(unsigned char * colorPixels, int vw, int vh, bool isTexture){

                unsigned char * cropArea;
				cropArea = new unsigned char[ vw * vh ];
				memset(cropArea, 0, sizeof(cropArea));

                // compose final result
                for(int i=0; i<vw; i++){
                    for(int j=0; j<vh; j++){
						int mainPixelPos;
						if(isTexture)
							mainPixelPos = ((vh-j-1)*vw + i) * 4;		//pixel position of video en FBO
						else
							mainPixelPos = (j*vw + i) * 4;		//pixel position of video

                        int subPixlPos = (j*vw + i);	//pixel position of croped area

						if(colorPixels[mainPixelPos]+3>100)
							cropArea[subPixlPos] = 255;   // R
						else
							cropArea[subPixlPos] = 0;   // R
					}
                }

				this->setFromPixels(cropArea, vw, vh);

				delete [] cropArea;
}
