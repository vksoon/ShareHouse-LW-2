#include "framework.h"
#include "ShareHouseLiteEngine.h"
#include "Core/Platform/Windows/WindowsSystem.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    ISystem* system = nullptr;

    /* TODO : 추상화 */
    system = new WindowsSystem();
    system->Init("ShareHouseLiteEngine");

    while (system->Loop()) {}

    delete system;
    system = nullptr;

    return 0;
}