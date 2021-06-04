#pragma once

#include "SHCoreMinimal.h"
#include "RenderSystem/SHRenderWindow.h"

#include <Windows.h>

namespace SHCore
{
	/* Create Windows Window */

	class SH_CORE_API SHD3D11RenderWindow : public SHRenderWindow
	{
	public:
		SHD3D11RenderWindow();
		virtual ~SHD3D11RenderWindow();

		virtual bool Create(const FRenderWindowOption& inRenderWindowOption) override;
		virtual bool Show() override;
		virtual void Destroy() override;
	private:
		static LRESULT WINAPI MsgProc(HWND inHWND, UINT inMSG, WPARAM inWPARAM, LPARAM inLPARAM);

		HINSTANCE m_Instance;
		HWND m_Wnd;
		MSG m_Msg;
	};
}