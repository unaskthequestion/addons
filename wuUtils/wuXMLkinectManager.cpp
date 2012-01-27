#include "wuXMLkinectManager.h"


wuXMLkinectManager::wuXMLkinectManager()
{

}

wuXMLkinectManager::~wuXMLkinectManager()
{
}

Skeleton wuXMLkinectManager::getSkeleton()
{

	Skeleton skel;

	vector<pieceInfo> * _frame = getNextFrame();
/*
	skel.head = (*_frame)[0].pos;
	skel.neck = (*_frame)[1].pos;
	skel.Lshoulder = (*_frame)[2].pos;
	skel.Rshoulder = (*_frame)[3].pos;
	skel.Lelbow = (*_frame)[4].pos;
	skel.Relbow = (*_frame)[5].pos;
	skel.Lhand = (*_frame)[6].pos;
	skel.Rhand = (*_frame)[7].pos;
	skel.torso = (*_frame)[8].pos;
	skel.Lhip = (*_frame)[9].pos;
	skel.Rhip = (*_frame)[10].pos;
	skel.Lknee = (*_frame)[11].pos;
	skel.Rknee = (*_frame)[12].pos;
	skel.Lfoot = (*_frame)[13].pos;
	skel.Rfoot = (*_frame)[14].pos;
*/
	return skel;
}

void wuXMLkinectManager::addFrame(Skeleton skel)
{

	// temporary frameInfo
	vector<pieceInfo> frame; // Create an empty row

	// temporary pieceInfo
	pieceInfo piece;

	piece.ang = 0;

/*	// add piece positions to frame
	piece.pos = skel.head;
	frame.push_back(piece);
	piece.pos = skel.neck;
	frame.push_back(piece);
	piece.pos = skel.Lshoulder;
	frame.push_back(piece);
	piece.pos = skel.Rshoulder;
	frame.push_back(piece);
	piece.pos = skel.Lelbow;
	frame.push_back(piece);
	piece.pos = skel.Relbow;
	frame.push_back(piece);
	piece.pos = skel.Lhand;
	frame.push_back(piece);
	piece.pos = skel.Rhand;
	frame.push_back(piece);
	piece.pos = skel.torso;
	frame.push_back(piece);
	piece.pos = skel.Lhip;
	frame.push_back(piece);
	piece.pos = skel.Rhip;
	frame.push_back(piece);
	piece.pos = skel.Lknee;
	frame.push_back(piece);
	piece.pos = skel.Rknee;
	frame.push_back(piece);
	piece.pos = skel.Lfoot;
	frame.push_back(piece);
	piece.pos = skel.Rfoot;
	frame.push_back(piece);
*/
	// add frame to filmInfo
	filmInfo.push_back(frame);
	num_frames++;


}
