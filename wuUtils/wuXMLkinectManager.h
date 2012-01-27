#ifndef wu_XML_KINECT_MANAGER_H
#define wu_XML_KINECT_MANAGER_H

#pragma once
#include "skelstruct.h"
#include "wuXMLvectorManager.h"


class wuXMLkinectManager : public wuXMLvectorManager
{
    public:
        wuXMLkinectManager();
        ~wuXMLkinectManager();

		Skeleton getSkeleton ();
		void addFrame(Skeleton skel);


};
#endif

