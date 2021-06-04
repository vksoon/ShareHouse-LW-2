#pragma comment(lib, "../../../Bin/SHCoreLib/x64/Debug/SHCoreLib_Debug.lib")

#include "SHCoreMinimal.h"
#include "RenderSystem/SHRenderWindow.h"
#include "RenderSystem/D3D11/SHD3D11RenderWindow.h"

using namespace SHCore;

int main()
{
	FRenderWindowOption renderWindowOption = SHRenderWindow::CreateRenderWindowOption(EWindowMode::Window, 1280, 720, 0, 0, "ShareHouseLiteEngine");

	SHRenderWindow* renderWindow = new SHD3D11RenderWindow();
	renderWindow->Create(renderWindowOption);

	while (renderWindow->Show()) {}

	renderWindow->Destroy();

	return 0;
}