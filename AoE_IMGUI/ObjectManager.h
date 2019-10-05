#pragma once
#include <cstdint>

class ObjectManager
{
public:
	char pad_0000[4]; //0x0000
	class Unit** units; //0x0004
	int32_t iObjectCount; //0x0008
	char pad_000C[4]; //0x000C
}; //Size: 0x0010#pragma once
