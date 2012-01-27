example:

	
ABANS *****************

               // pixels array of the mask
                unsigned char * maskPixels = grayDiff.getPixels();
                // pixel array of webcam video
                unsigned char * colorPixels = color.getPixels();

                unsigned char cropArea[ cropWidth * cropHeight * 4 +4 ];

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

                ofImage skin;
                skin.setImageType(OF_IMAGE_COLOR_ALPHA);
                skin.clear();
                skin.setFromPixels(cropArea, cropWidth,cropHeight, OF_IMAGE_COLOR_ALPHA );
 
ARA ******************

		    crImagePlus skin;
		    skin.crop(color.getPixels(), grayDiff.getPixels(), vw, vh, cropX, cropY, cropWidth, cropHeight);