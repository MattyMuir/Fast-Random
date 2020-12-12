#pragma once
#include <iostream>

typedef unsigned long UL;

#define znew (z=36969*(z&65535)+(z>>16))
#define wnew (w=18000*(w&65535)+(w>>16))
#define MWC ((znew<<16)+wnew )
#define SHR3 (jsr^=(jsr<<17), jsr^=(jsr>>13), jsr^=(jsr<<5))
#define CONG (jcong=69069*jcong+1234567)
#define FIB ((b=a+b),(a=b-a))
#define KISS ((MWC^CONG)+SHR3)
#define LFIB4 (c++,t[c]=t[c]+t[UC(c+58)]+t[UC(c+119)]+t[UC(c+178)])
#define SWB (c++,bro=(x<y),t[c]=(x=t[UC(c+34)])-(y=t[UC(c+19)]+bro))
#define UNI (KISS*2.328306e-10)
#define VNI ((long) KISS)*4.656613e-10
#define UC (unsigned char) /*a cast operation*/

class mRandomEngine
{
public:
	mRandomEngine();
	void SetSeeds(UL i1, UL i2, UL i3, UL i4, UL i5, UL i6);
	UL RandInt();
	unsigned char RandChar();
	unsigned char RandSmallInt(int min, int max);
	UL RandInt(int min, int max);
	float RandFloat();
	float RandFloat(float min, float max);
protected:
	UL full;
	unsigned char* buffer;
	int buffIndex;
	unsigned char* fullPtr = (unsigned char*)&full;
	UL z, w, jsr, jcong, a, b, t[256];
};