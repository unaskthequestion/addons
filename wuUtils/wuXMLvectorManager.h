#ifndef wu_XML_VECTOR_MANAGER_H
#define wu_XML_VECTOR_MANAGER_H

#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"

struct pieceInfo
{
	ofPoint pos;
	float ang;
};

class wuXMLvectorManager
{
    public:
        wuXMLvectorManager();
        ~wuXMLvectorManager();

		virtual void loadXML(string _filename, bool _bLoop=false);
		virtual void saveXML(string _filename);
		virtual vector<pieceInfo> * getFrame(int i);
		virtual vector<pieceInfo> * getNextFrame();
		virtual vector<pieceInfo> * getPrevFrame();
		virtual void addFrame (vector<pieceInfo> * _frame);
		virtual void deleteFrame (int i);
		virtual void clear();
		virtual int getNumFrames();
		virtual int getCurrentFrame();
		virtual void goto0();

		ofxXmlSettings XML;
		ofxXmlSettings XMLsave;

		int num_pieces;
		int num_frames;

		// frameInfo: un vector de pieceInfos (de num_pieces elements)
		// filmInfo: un vector de frameInfos (de num_frames elements)
		vector < vector<pieceInfo> > filmInfo;

		int current_frame;
		bool bLoop;
};
#endif

