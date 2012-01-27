#include "wuImagePlus.h"

wuImagePlus::wuImagePlus() {
//    init();
}

void  wuImagePlus::crop(unsigned char * colorPixels, unsigned char * maskPixels, int vw, int vh, int cropX, int cropY, int cropWidth, int cropHeight){

            pos.x = cropX + cropWidth/2;
            pos.y = cropY + cropHeight/2;
			ang = 0.0;

                unsigned char * cropArea;
				cropArea = new unsigned char[ cropWidth * cropHeight * 4 ];
				memset(cropArea, 0, sizeof(cropArea));

                // compose final result
                for(int i=0; i<cropWidth; i++){
                    for(int j=0; j<cropHeight; j++){
                        int mainPixelPos = ((j+cropY) *vw + (i+cropX)) * 3;		//pixel position of video
                        int subPixlPos = (j * cropWidth + i) * 4;	//pixel position of croped area

                        cropArea[subPixlPos] = colorPixels[mainPixelPos];   // R
                        cropArea[subPixlPos + 1] = colorPixels[mainPixelPos + 1];  // G
                        cropArea[subPixlPos + 2] = colorPixels[mainPixelPos + 2];  // B
                        // en aquest cas puc tenir semi-transparencies, i no només
                        // alpha=255 o alpha=0. Ara no sé què és millor
                        cropArea[subPixlPos + 3] = maskPixels[(j+cropY)*vw + (i+cropX)];  // alpha channel from mask pixel array
                    }
                }

                this->setImageType(OF_IMAGE_COLOR_ALPHA);
                this->clear();
                this->setFromPixels(cropArea, cropWidth,cropHeight, OF_IMAGE_COLOR_ALPHA );

				delete [] cropArea;
}

void  wuImagePlus::crop(unsigned char * colorPixels, unsigned char * maskPixels, int vw, int vh, ofRectangle rect){

            pos.x = rect.x + rect.width/2;
            pos.y = rect.y + rect.height/2;
			ang = 0.0;

                unsigned char * cropArea;
				cropArea = new unsigned char[ (int)rect.width * (int)rect.height * 4 ];
				memset(cropArea, 0, sizeof(cropArea));

                // compose final result
                for(int i=0; i<rect.width; i++){
                    for(int j=0; j<rect.height; j++){
                        int mainPixelPos = ((j+rect.y) *vw + (i+rect.x)) * 3;		//pixel position of video
                        int subPixlPos = (j * rect.width + i) * 4;	//pixel position of croped area

                        cropArea[subPixlPos] = colorPixels[mainPixelPos];   // R
                        cropArea[subPixlPos + 1] = colorPixels[mainPixelPos + 1];  // G
                        cropArea[subPixlPos + 2] = colorPixels[mainPixelPos + 2];  // B
                        // en aquest cas puc tenir semi-transparencies, i no només
                        // alpha=255 o alpha=0. Ara no sé què és millor
                        cropArea[subPixlPos + 3] = maskPixels[(j+(int)rect.y)*vw + (i+(int)rect.x)];  // alpha channel from mask pixel array
                    }
                }

                this->setImageType(OF_IMAGE_COLOR_ALPHA);
                this->clear();
                this->setFromPixels(cropArea, rect.width,rect.height, OF_IMAGE_COLOR_ALPHA );

				delete [] cropArea;
}


void  wuImagePlus::crop(unsigned char * colorPixels, unsigned char * maskPixels, int vw, int vh){

                pos.x = 0;
                pos.y = 0;
				ang = 0.0;

                int cropX = 0;
                int cropY = 0;
                int cropWidth = vw;
                int cropHeight = vh;

                unsigned char * cropArea = NULL;
				cropArea = new unsigned char[ cropWidth * cropHeight * 4  ];
                memset(cropArea, 0, sizeof(cropArea));

                // compose final result
                for(int i=0; i<cropWidth; i++){
                    for(int j=0; j<cropHeight; j++){
                        int mainPixelPos = ((j+cropY) *vw + (i+cropX)) * 3;		//pixel position of video
                        int subPixlPos = (j * cropWidth + i) * 4;	//pixel position of croped area

                        cropArea[subPixlPos] = colorPixels[mainPixelPos];   // R
                        cropArea[subPixlPos + 1] = colorPixels[mainPixelPos + 1];  // G
                        cropArea[subPixlPos + 2] = colorPixels[mainPixelPos + 2];  // B
                        // en aquest cas puc tenir semi-transparencies, i no només
                        // alpha=255 o alpha=0. Ara no sé què és millor
                        cropArea[subPixlPos + 3] = maskPixels[(j+cropY)*vw + (i+cropX)];  // alpha channel from mask pixel array
                    }
                }

                this->setImageType(OF_IMAGE_COLOR_ALPHA);
                this->clear();
                this->setFromPixels(cropArea, cropWidth,cropHeight, OF_IMAGE_COLOR_ALPHA );

				delete [] cropArea;

}

void  wuImagePlus::crop_unicolor(unsigned char * maskPixels, int vw, int vh){

                pos.x = 0;
                pos.y = 0;
				ang = 0.0;

                int cropX = 0;
                int cropY = 0;
                int cropWidth = vw;
                int cropHeight = vh;

                unsigned char * cropArea = NULL;
				cropArea = new unsigned char[ cropWidth * cropHeight * 4  ];
                memset(cropArea, 0, sizeof(cropArea));

                // compose final result
                for(int i=0; i<cropWidth; i++){
                    for(int j=0; j<cropHeight; j++){
                        int mainPixelPos = ((j+cropY) *vw + (i+cropX)) * 3;		//pixel position of video
                        int subPixlPos = (j * cropWidth + i) * 4;	//pixel position of croped area

                        cropArea[subPixlPos] = 255;   // R
                        cropArea[subPixlPos + 1] = 255;  // G
                        cropArea[subPixlPos + 2] = 255;  // B
                        // per tenir semi-transparencies
                       cropArea[subPixlPos + 3] = maskPixels[(j+cropY)*vw + (i+cropX)];  // alpha channel from mask pixel array
                    }
                }

                this->setImageType(OF_IMAGE_COLOR_ALPHA);
                this->clear();
                this->setFromPixels(cropArea, cropWidth,cropHeight, OF_IMAGE_COLOR_ALPHA );

				delete [] cropArea;

}

void  wuImagePlus::crop_thres(unsigned char * colorPixels, unsigned char * maskPixels, int vw, int vh, int cropX, int cropY, int cropWidth, int cropHeight, int thres){

            pos.x = cropX + cropWidth/2;
            pos.y = cropY + cropHeight/2;
			ang = 0.0;

            unsigned char * cropArea = NULL;
			cropArea = new unsigned char[ cropWidth * cropHeight * 4  ];
            memset(cropArea, 0, sizeof(cropArea));

            for(int i=0; i<cropWidth; i++){ // eix x
                for(int j=0; j<cropHeight; j++){ // eix y
                    int mainPixelPos = ((j+cropY) *vw + (i+cropX)) * 3;		//pixel position of video
                    int subPixlPos = (j * cropWidth + i) * 4;	//pixel position of croped area

                    cropArea[subPixlPos] = colorPixels[mainPixelPos];   // R
                    cropArea[subPixlPos + 1] = colorPixels[mainPixelPos + 1];  // G
                    cropArea[subPixlPos + 2] = colorPixels[mainPixelPos + 2];  // B
                    if (maskPixels[(j+cropY)*vw + (i+cropX)]>thres)
                        cropArea[subPixlPos + 3] = 255;  // alpha channel from mask pixel array
                    else
                        cropArea[subPixlPos + 3] = 0;  // alpha channel from mask pixel array
                }
           }
           this->setImageType(OF_IMAGE_COLOR_ALPHA);
           this->clear();
           this->setFromPixels(cropArea, cropWidth,cropHeight, OF_IMAGE_COLOR_ALPHA );

		   delete [] cropArea;
}

void  wuImagePlus::crop_thres(unsigned char * colorPixels, unsigned char * maskPixels, int vw, int vh, int thres){

            pos.x = 0;
            pos.y = 0;
			ang = 0.0;

            int cropX = 0;
            int cropY = 0;
            int cropWidth = vw;
            int cropHeight = vh;

            unsigned char * cropArea = NULL;
			cropArea = new unsigned char[ cropWidth * cropHeight * 4  ];
            memset(cropArea, 0, sizeof(cropArea));

            for(int i=0; i<cropWidth; i++){ // eix x
                for(int j=0; j<cropHeight; j++){ // eix y
                    int mainPixelPos = ((j+cropY) *vw + (i+cropX)) * 3;		//pixel position of video
                    int subPixlPos = (j * cropWidth + i) * 4;	//pixel position of croped area

                    cropArea[subPixlPos] = colorPixels[mainPixelPos];   // R
                    cropArea[subPixlPos + 1] = colorPixels[mainPixelPos + 1];  // G
                    cropArea[subPixlPos + 2] = colorPixels[mainPixelPos + 2];  // B
                    if (maskPixels[(j+cropY)*vw + (i+cropX)]> thres)
                        cropArea[subPixlPos + 3] = 255;  // alpha channel from mask pixel array
                    else
                        cropArea[subPixlPos + 3] = 0;  // alpha channel from mask pixel array
                }
           }
           this->setImageType(OF_IMAGE_COLOR_ALPHA);
           this->clear();
           this->setFromPixels(cropArea, cropWidth,cropHeight, OF_IMAGE_COLOR_ALPHA );

		   delete [] cropArea;
}


void  wuImagePlus::deleteColor(int hue, int sat, int val, int hueRange, int satRange, int valRange, bool isolate){

        // SET
		ofxCvColorImage			videoColorCvImage;
   		ofxCvColorImage			videoColorHSVCvImage;
		ofxCvGrayscaleImage		videoGrayscaleHueImage;
		ofxCvGrayscaleImage		videoGrayscaleSatImage;
		ofxCvGrayscaleImage		videoGrayscaleBriImage;

        videoColorCvImage.allocate(width, height);
        videoColorHSVCvImage.allocate(width, height);
        videoGrayscaleHueImage.allocate(width, height);
        videoGrayscaleSatImage.allocate(width, height);
        videoGrayscaleBriImage.allocate(width, height);

        videoColorCvImage.setFromPixels(this->getPixels(), width, height);

		videoColorHSVCvImage = videoColorCvImage;
		videoColorHSVCvImage.convertRgbToHsv();

		videoColorHSVCvImage.convertToGrayscalePlanarImages(videoGrayscaleHueImage, videoGrayscaleSatImage, videoGrayscaleBriImage);

		videoGrayscaleHueImage.flagImageChanged();		// this is fixing a bug in OF 0.06
		videoGrayscaleSatImage.flagImageChanged();
		videoGrayscaleBriImage.flagImageChanged();

		unsigned char * colorHsvPixels = videoColorHSVCvImage.getPixels();

        unsigned char * grayPixels = NULL;
		grayPixels = new unsigned char[width * height];

		for (int i = 0; i < width*height; i++){

				// since hue is cyclical:
				int hueDiff = colorHsvPixels[i*3] - hue;
				if (hueDiff < -127) hueDiff += 255;
				if (hueDiff > 127) hueDiff -= 255;


				if ( (fabs((float)hueDiff) < hueRange) &&
					(colorHsvPixels[i*3+1] > (sat - satRange) && colorHsvPixels[i*3+1] < (sat + satRange)) &&
					(colorHsvPixels[i*3+2] > (val - valRange) && colorHsvPixels[i*3+2] < (val + valRange))){

					if (isolate)
                        grayPixels[i] = 255;
					else
                        grayPixels[i] = 0;

				} else {

					if (isolate)
                        grayPixels[i] = 0;
					else
                        grayPixels[i] = 255;
				}

			}

		    this->crop_thres(videoColorCvImage.getPixels(), grayPixels, width, height, 1);
			delete [] grayPixels;
};

void  wuImagePlus::deleteColor(char _color, bool isolate){

        int hue, sat, val, hueRange, satRange, valRange;

        switch(_color)
        {
            case 'g': // green
                hue=53;
                sat=212;
                val=149;
                hueRange=35;
                satRange=107;
                valRange=62;
                break;
            case 'm':  // ma, color carn
                hue=4;
                sat=88;
                val=124;
                hueRange=9;
                satRange=55;
                valRange=247;
                break;
            case 'b': // blue
                hue=113;
                sat=254;
                val=117;
                hueRange=46;
                satRange=151;
                valRange=103;
                break;
            case 'r': // red
                hue=5;
                sat=222;
                val=181;
                hueRange=107;
                satRange=60;
                valRange=51;
                break;
        }

        deleteColor(hue, sat, val, hueRange, satRange, valRange, isolate);
}

void  wuImagePlus::getHSVPixel(int pixel, int* hue, int* sat, int* val){

        // SET
		ofxCvColorImage			videoColorCvImage;
   		ofxCvColorImage			videoColorHSVCvImage;
		ofxCvGrayscaleImage		videoGrayscaleHueImage;
		ofxCvGrayscaleImage		videoGrayscaleSatImage;
		ofxCvGrayscaleImage		videoGrayscaleBriImage;

        videoColorCvImage.allocate(width, height);
        videoColorHSVCvImage.allocate(width, height);
        videoGrayscaleHueImage.allocate(width, height);
        videoGrayscaleSatImage.allocate(width, height);
        videoGrayscaleBriImage.allocate(width, height);

        videoColorCvImage.setFromPixels(this->getPixels(), width, height);

		videoColorHSVCvImage = videoColorCvImage;
		videoColorHSVCvImage.convertRgbToHsv();

		videoColorHSVCvImage.convertToGrayscalePlanarImages(videoGrayscaleHueImage, videoGrayscaleSatImage, videoGrayscaleBriImage);

		videoGrayscaleHueImage.flagImageChanged();		// this is fixing a bug in OF 0.06
		videoGrayscaleSatImage.flagImageChanged();
		videoGrayscaleBriImage.flagImageChanged();

		*hue = videoGrayscaleHueImage.getPixels()[pixel];
		*sat = videoGrayscaleSatImage.getPixels()[pixel];
		*val = videoGrayscaleBriImage.getPixels()[pixel];
}
/*-----------------------------------  
void wuImagePlus::mirror(bool horizontal, bool vertical){  
    flipPixels(myPixels, horizontal, vertical);  
      
    update();  
}  

//----------------------------------------------------  
void wuImagePlus::flipPixels(ofPixels &pix, bool horizontal, bool vertical){  
    if(!horizontal && !vertical)  
        return;  
      
    FIBITMAP * bmp                  = getBmpFromPixels(pix);  
    bool horSuccess = false, vertSuccess = false;  
      
    if(horizontal)  
        horSuccess = FreeImage_FlipHorizontal(bmp);  
    if(vertical)  
        vertSuccess = FreeImage_FlipVertical(bmp);  
  
    if(horSuccess || vertSuccess)  
        putBmpIntoPixels(bmp, pix);  
      
    if (bmp != NULL)                FreeImage_Unload(bmp);  
}  
*/
void  wuImagePlus::alpha2RGB(unsigned char * colorPixels, int vw, int vh, bool bWhite){

	            int cropX = 0;
			    int cropY = 0;
		        int cropWidth = vw;
	            int cropHeight = vh;

	            pos.x = cropX + cropWidth/2;
		        pos.y = cropY + cropHeight/2;
				ang = 0.0;

                unsigned char * cropArea;
				cropArea = new unsigned char[ cropWidth * cropHeight * 3 ];
				memset(cropArea, 0, sizeof(cropArea));

                // compose final result
                for(int i=0; i<cropWidth; i++){
                    for(int j=0; j<cropHeight; j++){
                        int mainPixelPos = ((j+cropY) *vw + (i+cropX)) * 4;		//pixel position of video
                        int subPixlPos = (j * cropWidth + i) * 3;	//pixel position of croped area

						if(colorPixels[mainPixelPos + 3]>250)
						{
							cropArea[subPixlPos] = colorPixels[mainPixelPos];   // R
							cropArea[subPixlPos + 1] = colorPixels[mainPixelPos + 1];  // G
							cropArea[subPixlPos + 2] = colorPixels[mainPixelPos + 2];  // B
						}else
						{
							if(bWhite)
							{
								cropArea[subPixlPos] = 255;   // R
								cropArea[subPixlPos + 1] = 255;  // G
								cropArea[subPixlPos + 2] = 255;  // B
							}
							else
							{
								cropArea[subPixlPos] = 0;   // R
								cropArea[subPixlPos + 1] = 0;  // G
								cropArea[subPixlPos + 2] = 0;  // B
							}
						}
					}
                }

                this->setImageType(OF_IMAGE_COLOR);
                this->clear();
                this->setFromPixels(cropArea, cropWidth,cropHeight, OF_IMAGE_COLOR );

				delete [] cropArea;
}

// borra les transparències d' un rectangle, re-pintant els pixels amb color aleatori
// (usat per eliminar un blob intern o hole)
void  wuImagePlus::eraseTrans(int cropX2, int cropY2, int cropW2, int cropH2)
{
				int vw = this->getWidth();
				int vh = this->getHeight();

				unsigned char * mypixels = this->getPixels();

                unsigned char * cropArea;
				cropArea = new unsigned char[ vw * vh * 4 ];
				memset(cropArea, 0, sizeof(cropArea));

				// copy pixels
				for(int i=0; i<vw*vh*4;i++)
					cropArea[i] = mypixels[i];

				int iniX = - min(cropX2-1, 1);
				int iniY = - min(cropY2-1, 1);
				cropW2 = min(cropW2+1,vw-3);
				cropH2 = min(cropH2+1,vh-3);

               // compose final result
                for(int i=iniX; i<cropW2; i++){
                    for(int j=iniY; j<cropH2; j++){
						int mainPixelPos = ((j+cropY2)*vw + (i+cropX2)) * 4;		//pixel position of video
						
						if(cropArea[mainPixelPos +3]<255)
						{
							int PosPixel;
							
							do{	
								PosPixel = ofRandom(0,vw*vh*4);
							}while (cropArea[PosPixel+3] < 255);


							cropArea[mainPixelPos +0] = (cropArea[PosPixel+0]+cropArea[mainPixelPos +0 -4])/2;	
							cropArea[mainPixelPos +1] = (cropArea[PosPixel+1]+cropArea[mainPixelPos +1 -4])/2;
							cropArea[mainPixelPos +2] = (cropArea[PosPixel+2]+cropArea[mainPixelPos +2 -4])/2;
							cropArea[mainPixelPos +3] = (cropArea[PosPixel+3]+cropArea[mainPixelPos +3 -4])/2;
						}
				
					}
                }

           this->setImageType(OF_IMAGE_COLOR_ALPHA);
           this->clear();
           this->setFromPixels(cropArea, vw,vh, OF_IMAGE_COLOR_ALPHA );

		   delete [] cropArea;
}

// retalla el rectangle a la imatge, sense mask
// crea una imatge amb alpha, tot i que potser no caldria
void  wuImagePlus::crop(unsigned char * colorPixels, int vw, int vh, int cropX, int cropY, int cropWidth, int cropHeight){

            pos.x = cropX + cropWidth/2;
            pos.y = cropY + cropHeight/2;
			ang = 0.0;

                unsigned char * cropArea;
				cropArea = new unsigned char[ cropWidth * cropHeight * 4 ];
				memset(cropArea, 0, sizeof(cropArea));

                // compose final result
                for(int i=0; i<cropWidth; i++){
                    for(int j=0; j<cropHeight; j++){
                        int mainPixelPos = ((j+cropY) *vw + (i+cropX)) * 3;		//pixel position of video
                        int subPixlPos = (j * cropWidth + i) * 4;	//pixel position of croped area

                        cropArea[subPixlPos] = colorPixels[mainPixelPos];   // R
                        cropArea[subPixlPos + 1] = colorPixels[mainPixelPos + 1];  // G
                        cropArea[subPixlPos + 2] = colorPixels[mainPixelPos + 2];  // B
                        cropArea[subPixlPos + 3] = 255;  // alpha channel from mask pixel array
                    }
                }

                this->setImageType(OF_IMAGE_COLOR_ALPHA);
                this->clear();
                this->setFromPixels(cropArea, cropWidth,cropHeight, OF_IMAGE_COLOR_ALPHA );

				delete [] cropArea;
}

bool  wuImagePlus::capture(ofxCvColorImage *color, ofxCvGrayscaleImage * grayDiff, int vw, int vh){
			// openCV
			bool bCaptured = false;

			ofxCvContourFinder		contour;

//		    contour.blobs.clear();
			contour.findContours(*grayDiff, 20, (vw*vh)/2, 10, false);	// find holes

             if (contour.nBlobs>0){

                int cropX = contour.blobs[0].boundingRect.x;
                int cropY = contour.blobs[0].boundingRect.y;
                int cropWidth = contour.blobs[0].boundingRect.width;
                int cropHeight = contour.blobs[0].boundingRect.height;

                // bitmap
				grayDiff->blur(5);
                this->crop(color->getPixels(), grayDiff->getPixels(), vw, vh, cropX, cropY, cropWidth, cropHeight);
				bCaptured = true;
			}

		 return bCaptured;
}

