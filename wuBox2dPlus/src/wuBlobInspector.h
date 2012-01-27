
#ifndef wu_BLOBINSPECTOR_H
#define wu_BLOBINSPECTOR_H

#pragma once
#include "wuSkin.h"
#include "wuBaseManager.h"

class wuBlobInspector : public wuBaseManager
{
    public:
        wuBlobInspector();
        ~wuBlobInspector();

        void draw(bool bDrawlines=false, int offX=0);
};
#endif

