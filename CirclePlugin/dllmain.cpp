// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <memory>
#include <string>
#include "Circle.h"

std::string GetPluginName()
{
    return "Circle";
}

std::shared_ptr<Curve> GetPluginCurve(double r)
{
    return std::make_shared<Circle>(r);
}

BOOL APIENTRY DllMain(HMODULE hModule,
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