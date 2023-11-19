// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <memory>
#include <string>
#include "Helixe.h"

std::string GetPluginName()
{
    return "Helix";
}
std::shared_ptr<Curve> _declspec(dllexport) GetPluginCurve()
{
    return std::make_shared<Helixe>();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

