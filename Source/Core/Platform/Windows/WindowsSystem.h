#pragma once

#include "framework.h"
#include "Core/Platform/System.h"

class WindowsSystem : public ISystem
{
public:
	WindowsSystem();
	virtual ~WindowsSystem();

	virtual bool Init(const std::string& inWindowName)	override;
	virtual bool Loop()									override;
	virtual bool Destroy()								override;

	HWND GetHWND() { return _Wnd; }
	bool IsLoop() { return _IsLoop; }
private:
	static LRESULT WINAPI MsgProc(HWND inHWND, UINT inMSG, WPARAM inWPARAM, LPARAM inLPARAM);

	HINSTANCE _Instance;
	HWND _Wnd;
	MSG _Msg;

	std::string _WindowName;

	bool _IsLoop = true;
};