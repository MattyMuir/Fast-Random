#include <iostream>
#include <iomanip>
#include <vector>

#include "mRandomEngine.h"
#include "Timer.h"

size_t HighestOneBitPosition(uint64_t value)
{
    size_t result = 0;
    if (0xFFFFFFFF00000000 & value) { value >>= (1 << 5); result |= (1 << 5); }
    if (0x00000000FFFF0000 & value) { value >>= (1 << 4); result |= (1 << 4); }
    if (0x000000000000FF00 & value) { value >>= (1 << 3); result |= (1 << 3); }
    if (0x00000000000000F0 & value) { value >>= (1 << 2); result |= (1 << 2); }
    if (0x000000000000000C & value) { value >>= (1 << 1); result |= (1 << 1); }
    if (0x0000000000000002 & value) { result |= (1 << 0); }
    return result;
}

bool mulSafe1(uint64_t a, uint64_t b)
{
	size_t a_bits = HighestOneBitPosition(a), b_bits = HighestOneBitPosition(b);
	return (a_bits + b_bits <= 62);
}

bool mulSafe2(uint64_t a, uint64_t b)
{
	return a < (UINT64_MAX / b);
}

int main()
{
    //change
    unsigned int testSize = UINT32_MAX/100;

    std::vector<uint64_t> testDataA;
    std::vector<uint64_t> testDataB;
    mRandomEngine eng = mRandomEngine();

    for (int i = 0; i < testSize; i++)
    {
        testDataA.push_back((uint64_t)exp(eng.RandFloat(0, 32)));
        testDataB.push_back((uint64_t)exp(eng.RandFloat(0, 32)));
    }

    std::vector<bool> isSafe1;
    std::vector<bool> isSafe2;

    Timer t1;
    for (int i = 0; i < testSize; i++)
    {
        isSafe1.push_back(mulSafe1(testDataA[i], testDataB[i]));
    }
    t1.Stop();

    Timer t2;
    for (int i = 0; i < testSize; i++)
    {
        isSafe2.push_back(mulSafe2(testDataA[i], testDataB[i]));
    }
    t2.Stop();

    /*for (int i = 0; i < testSize; i++)
    {
        std::cout << isSafe1[i] << ", " << isSafe2[i] << std::endl;
    }*/

    std::cout << t1.duration << std::endl;
    std::cout << t2.duration << std::endl;
    //std::cin.get();
}