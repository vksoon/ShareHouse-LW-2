#include "SHD3D11RenderWindow.h"

using namespace SHCore;

SHD3D11RenderWindow::SHD3D11RenderWindow()
{
	m_Instance = nullptr;
	m_Wnd = nullptr;

	ZeroMemory(&m_Msg, sizeof(m_Msg));
}

SHD3D11RenderWindow::~SHD3D11RenderWindow()
{
	Destroy();
}

bool SHD3D11RenderWindow::Create(const FRenderWindowOption& inRenderWindowOption)
{
	m_RenderWindowOption = inRenderWindowOption;

	const char* windowTitleStr = m_RenderWindowOption.GetWindowTitle().c_str();

	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, SHD3D11RenderWindow::MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		windowTitleStr, NULL
	};
	RegisterClassEx(&wc);

	m_Instance = wc.hInstance;
	m_Wnd = CreateWindowA(windowTitleStr, windowTitleStr,
		WS_OVERLAPPEDWINDOW, m_RenderWindowOption.GetPosX(), m_RenderWindowOption.GetPosY(), m_RenderWindowOption.GetWidth(), m_RenderWindowOption.GetHeight(),
		NULL, NULL, m_Instance, NULL);

	ShowWindow(m_Wnd, SW_SHOWDEFAULT);
	UpdateWindow(m_Wnd);

	return true;
}

bool SHD3D11RenderWindow::Show()
{
	if (m_Msg.message == WM_QUIT)
		return false;

	if (PeekMessage(&m_Msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&m_Msg);
		DispatchMessage(&m_Msg);
	}

	return true;
}

void SHD3D11RenderWindow::Destroy()
{
	DestroyWindow(m_Wnd);
	UnregisterClass(m_RenderWindowOption.GetWindowTitle().c_str(), m_Instance);
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