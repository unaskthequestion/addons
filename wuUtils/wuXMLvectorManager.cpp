#include "wuXMLvectorManager.h"


wuXMLvectorManager::wuXMLvectorManager()
{

}

wuXMLvectorManager::~wuXMLvectorManager()
{
}


void wuXMLvectorManager::loadXML(string _filename, bool _bLoop)
{

	bLoop = _bLoop;
	current_frame = -1;

	clear();

	if( XML.loadFile(_filename) ){
		cout << "xml loaded";
	}else{
		cout << "unable to load xml. check data/ folder";
		return;
	}

	// add info to filmInfo
//	num_pieces	= XML.getValue("PIECES"); // <PIECES> 5 </PIECES>
//	num_frames	= XML.getValue("FRAMES"); // <FRAMES> 340 </FRAMES>

//		//lets see how many <FRAME> </FRAME> tags there are in the xml file
	int num_frames = XML.getNumTags("FRAME:PT");

	cout << "FRAMES=" << num_frames << endl;

	for(int j = 0; j < num_frames; j++){

			//we push into the last STROKE tag
			//this temporarirly treats the tag as
			//the document root.
			XML.pushTag("FRAME", j);

			//we see how many points we have stored in <PT> tags
			int num_pieces = XML.getNumTags("PT");

			if(num_pieces > 0){

//				if (numPtTags != num_pieces)
//					cout << "numero de peces inconsistent " << numPtTags;

	
				// temporary frameInfo
				vector<pieceInfo> frame; // Create an empty row

				for(int i = 0; i < num_pieces; i++){
					//the last argument of getValue can be used to specify
					//which tag out of multiple tags you are refering to.
					
					// temporary pieceInfo
					pieceInfo piece;

					piece.pos.x = XML.getValue("PT:X", 0, i);
					piece.pos.y = XML.getValue("PT:Y", 0, i);
					piece.ang = XML.getValue("PT:ANG", 0, i) / 100.0;
					// store ints -> convert int to float with /100

					// add piece position to frame
					frame.push_back(piece);
				}

				// add frame to filmInfo
				filmInfo.push_back(frame);

			}

			//this pops us out of the STROKE tag
			//sets the root back to the xml document
			XML.popTag();
	}
}

vector<pieceInfo> * wuXMLvectorManager::getFrame(int i)
{
	return &filmInfo[i];
}
vector<pieceInfo> * wuXMLvectorManager::getNextFrame()
{
	current_frame++;
	if(current_frame >= filmInfo.size())
	{
		if(bLoop)
			current_frame = 1;
		else
			current_frame = filmInfo.size()-1;
	}

	return &filmInfo[current_frame];
}

vector<pieceInfo> * wuXMLvectorManager::getPrevFrame()
{
	current_frame--;
	if(current_frame < 0)
			current_frame = 0;

	return &filmInfo[current_frame];
}

void wuXMLvectorManager::addFrame (vector<pieceInfo> * _frame)
{
	// temporary frameInfo
	vector<pieceInfo> frame; // Create an empty row

	for(int i = 0; i < _frame->size(); i++){
					
		// temporary pieceInfo
		pieceInfo piece;

		piece.pos.x = (*_frame)[i].pos.x;
		piece.pos.y = (*_frame)[i].pos.y;
		piece.ang = (*_frame)[i].ang;

		// add piece position to frame
		frame.push_back(piece);
	}

	filmInfo.push_back(frame);
	current_frame = filmInfo.size()-1;
}
void wuXMLvectorManager::deleteFrame (int i)
{
	// erase the i frame
	filmInfo.erase(filmInfo.begin()+i);
}
void wuXMLvectorManager::saveXML (string _filename)
{

	cout << "\n" << filmInfo.size() << "\n";

	for(int j = 0; j < filmInfo.size(); j++){

		XMLsave.addTag("FRAME");

		XMLsave.pushTag("FRAME", j);

		//-------------
		//we also want to record the stroke

		//lets store the drag of the user.
		//we will push into the most recent
		//<FRAME> tag - add the mouse points
		//then pop out
		

		// temporary frameInfo
		vector<pieceInfo> * frame; // Create an empty vector

		frame = &(filmInfo[j]);

		cout << frame->size() << ",";

		for(int i = 0; i < frame->size(); i++){

			int tagNum = XMLsave.addTag("PT");
			XMLsave.setValue("PT:X", (int)(*frame)[i].pos.x, tagNum);
			XMLsave.setValue("PT:Y", (int)(*frame)[i].pos.y, tagNum);
			XMLsave.setValue("PT:ANG", (int)((*frame)[i].ang*100), tagNum); 
			// store ints -> onvert float to int with *100
		}
		XMLsave.popTag(); // close FRAME

	}
	XMLsave.saveFile(_filename);

}

void wuXMLvectorManager::clear()
{

	for(int j = 0; j < filmInfo.size(); j++){

		// temporary frameInfo
		vector<pieceInfo> * frame; // Create an empty vector
		frame = &(filmInfo[j]);
		frame->clear();
	}
	filmInfo.clear();
}
int wuXMLvectorManager::getNumFrames()
{
	return filmInfo.size();
}
int wuXMLvectorManager::getCurrentFrame()
{
	return current_frame;
}
void wuXMLvectorManager::goto0()
{
	current_frame=-1;
}