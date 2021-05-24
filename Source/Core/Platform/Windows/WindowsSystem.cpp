#include "WindowsSystem.h"

WindowsSystem::WindowsSystem()
{
	_Instance = nullptr;
	_Wnd = nullptr;

	ZeroMemory(&_Msg, sizeof(_Msg));
}

WindowsSystem::~WindowsSystem()
{
	Destroy();
}

bool WindowsSystem::Init(const std::string& inWindowName)
{
	_WindowName = inWindowName;
	_IsLoop = true;

	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, WindowsSystem::MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		L"WindowsSystem", NULL
	};
	RegisterClassEx(&wc);

	_Instance = wc.hInstance;
	_Wnd = CreateWindowA("WindowsSystem", _WindowName.c_str(),
		WS_OVERLAPPEDWINDOW, 100, 100, 1280, 720, NULL, NULL, wc.hInstance, NULL);

	ShowWindow(_Wnd, SW_SHOWDEFAULT);
	UpdateWindow(_Wnd);

	return true;
}

bool WindowsSystem::Loop()
{
	if (_Msg.message == WM_QUIT)
		_IsLoop = false;

	if (PeekMessage(&_Msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&_Msg);
		DispatchMessage(&_Msg);
	}

	return _IsLoop;
}

bool WindowsSystem::Destroy()
{
	DestroyWindow(_Wnd);
	UnregisterClass(L"WindowsSystem", _Instance);

	return true;
}

LRESULT WINAPI WindowsSystem::MsgProc(HWND inHWND, UINT inMSG, WPARAM inWPARAM, LPARAM inLPARAM)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (inMSG)
	{
	case WM_PAINT:
		hdc = BeginPaint(inHWND, &ps);
		EndPaint(inHWND, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(inHWND, inMSG, inWPARAM, inLPARAM);
	}

	return 0;
}