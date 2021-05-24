#pragma once
#include <string>

class ISystem
{
public:
	virtual ~ISystem() {}

	virtual bool Init(const std::string& inWindowName)	= 0;
	virtual bool Loop()									= 0;
	virtual bool Destroy()								= 0;
};