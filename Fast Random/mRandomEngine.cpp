#include "mRandomEngine.h"

mRandomEngine::mRandomEngine()
{
	buffIndex = 0;

	z = 362436069;
	w = 521288629;
	jsr = 123456789;
	jcong = 380116160;
	a = 224466889;
	b = 7584631;
	for (int i = 0; i < 256; i = i + 1)
		t[i] = KISS;

	buffIndex = 0;
	full = MWC;
	buffer = static_cast<unsigned char*>(static_cast<void*>(&full));
}

void mRandomEngine::SetSeeds(UL i1, UL i2, UL i3, UL i4, UL i5, UL i6)
{
	int i; z = i1; w = i2, jsr = i3; jcong = i4; a = i5; b = i6;
	for (i = 0; i < 256; i = i + 1)
		t[i] = KISS;

	buffIndex = 0;
	full = MWC;
	buffer = static_cast<unsigned char*>(static_cast<void*>(&full));
}

UL mRandomEngine::RandInt()
{
	return MWC;
}

unsigned char mRandomEngine::RandChar()
{
	full = MWC;
	return *fullPtr;
}

unsigned char mRandomEngine::RandSmallInt(int min, int max)
{
	if (buffIndex > 3)
	{
		full = MWC;
		buffer = static_cast<unsigned char*>(static_cast<void*>(&full));
		buffIndex = 0;
	}
	buffIndex++;
	return buffer[buffIndex - 1] % (max - min + 1) + min;
}

UL mRandomEngine::RandInt(int min, int max)
{
	return MWC % (max - min + 1) + min;
}

float mRandomEngine::RandFloat()
{
	return VNI;
}

float mRandomEngine::RandFloat(float min, float max)
{
	return UNI * (max - min) + min;
}
