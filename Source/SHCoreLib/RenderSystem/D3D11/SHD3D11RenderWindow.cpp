#include "SHD3D11RenderWindow.h"

using namespace SHCore;

SHD3D11RenderWindow::SHD3D11RenderWindow()
{
	hInstance = nullptr;
	hWnd = nullptr;

	ZeroMemory(&Msg, sizeof(Msg));
}

SHD3D11RenderWindow::~SHD3D11RenderWindow()
{
	Destroy();
}

bool SHD3D11RenderWindow::Create(const FRenderWindowOption& inRenderWindowOption)
{
	RenderWindowOption = inRenderWindowOption;

	const char* windowTitleStr = RenderWindowOption.GetWindowTitle().c_str();

	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, SHD3D11RenderWindow::MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		windowTitleStr, NULL
	};
	RegisterClassEx(&wc);

	hInstance = wc.hInstance;
	hWnd = CreateWindowA(windowTitleStr, windowTitleStr,
		WS_OVERLAPPEDWINDOW, RenderWindowOption.GetPosX(), RenderWindowOption.GetPosY(), RenderWindowOption.GetWidth(), RenderWindowOption.GetHeight(),
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);

	return true;
}

bool SHD3D11RenderWindow::Show()
{
	if (Msg.message == WM_QUIT)
		return false;

	if (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return true;
}

void SHD3D11RenderWindow::Destroy()
{
	DestroyWindow(hWnd);
	UnregisterClass(RenderWindowOption.GetWindowTitle().c_str(), hInstance);
}

LRESULT WINAPI SHD3D11RenderWindow::MsgProc(HWND inHWND, UINT inMSG, WPARAM inWPARAM, LPARAM inLPARAM)
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