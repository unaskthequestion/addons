#include "wuGestures.h"

/******** SHAKE ***************/

wuGest_shake::wuGest_shake()
{

}

wuGest_shake::~wuGest_shake()
{
}

void wuGest_shake::setup(){
sTreshold = 1.6;  
trig=0;  
shake=0;  
shakemaxnumber = 1;  
timeofgesture = 1000;  
oldx=0;
x=0;
}

void wuGest_shake::setTime(int _time){
	timeofgesture = _time;  
}


int wuGest_shake::update(int _x)
{
	x = _x;
/*
	if(_Yhand>_Yshoulder && bIsAbove==false){  
		trig++;  
		startshake = ofGetElapsedTimeMillis();
		bIsAbove = true;
		cout << "UP ";
	}  
	if(_Yhand<_Yshoulder && bIsAbove==true){  
		trig++;  
		startshake = ofGetElapsedTimeMillis();
		bIsAbove = false;
		cout << "DOWN ";
	}  

	cout << (ofGetElapsedTimeMillis() -startshake);

	if ((ofGetElapsedTimeMillis() - startshake) > timeofgesture) {  
		trig--;
		startshake = ofGetElapsedTimeMillis();
		if (trig<0)
			trig=0;
	}  

//	cout << startshake;
	cout << "_";
//	cout << trig;
*/
	if(accx<-sTreshold && trig ==0){  
    trig = 1;  
    startshake = ofGetElapsedTimeMillis();  
}  
if(accx>sTreshold && trig == 1){  
    trig=2;  
}  
if(accx<-sTreshold && trig == 2){  
    trig=3;  
}  
if(accx>sTreshold && trig == 3){  
    trig=4;  
}  
if (trig==4) {  
    shake++;  
    trig=0;  
}  
if ((ofGetElapsedTimeMillis() - startshake) > timeofgesture) {  
	shake=shake-3;
	if (shake<0)
		shake=0;
	trig=0;  
}  
  
  
	accx=x-oldx;  
	oldx=x;

	return shake;
}
/**********************************/
