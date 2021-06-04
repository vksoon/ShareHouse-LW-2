#include "SHRenderWindow.h"

using namespace SHCore;

FRenderWindowOption SHRenderWindow::CreateRenderWindowOption(
	EWindowMode inWindowMode,
	int32 inWidth, int32 inHeight,
	int32 inPosX, int32 inPosY,
	const std::string& inWindowTitle)
{
	return FRenderWindowOption(inWindowMode, inWidth, inHeight, inPosX, inPosY, inWindowTitle);
}

