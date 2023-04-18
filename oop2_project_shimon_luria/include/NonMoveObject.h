#pragma once
#include "Object.h"

class NonMoveObject :public Object
{
public:
	NonMoveObject(int, int);
	virtual std::string name() { return ""; }
};