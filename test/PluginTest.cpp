#include "Curve.h"
#include <Windows.h>
#include <memory>
#include <algorithm>
#include <utility>
#include <vector>

typedef std::string(*LPGETPLUGNAME)();
typedef std::shared_ptr<Curve>(*LPGETPLUGINCURVE)(double r, double none);

std::wstring DllsPath()
{
    WCHAR buffer[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    return ((std::wstring(buffer).substr(0, pos)).append(L"\\*.dll"));
}

std::vector<std::pair<int, HMODULE>> EnumeratePlugins()
{
    std::vector<std::pair<int, HMODULE>> result;
    int index = 1;
    WIN32_FIND_DATA wfd;
    HANDLE hSearchHandle;

    std::wstring searchTemplate = DllsPath();
    hSearchHandle = FindFirstFile(searchTemplate.c_str(), &wfd);
    if (hSearchHandle == INVALID_HANDLE_VALUE)
        return result;

    do
    {
        HMODULE dll = LoadLibrary(wfd.cFileName);
        if (dll == NULL)
            continue;

        if (GetProcAddress(dll, "GetPluginName") != NULL)
        {
            result.push_back(std::make_pair(index, dll));
            index++;
        }
        else
        {
            FreeLibrary(dll);
        }
    } while (FindNextFile(hSearchHandle, &wfd) != 0);
    FindClose(hSearchHandle);
    return result;
}

int main() {
    using std::cout;
    using std::endl;
    using std::vector;
    using std::shared_ptr;
    using std::make_shared;
    using std::dynamic_pointer_cast;
    using std::sort;
    srand(time(NULL));

    std::vector<std::pair<int, HMODULE>> dlls = EnumeratePlugins();
    int const LENGTH = 10;
    double const RANDOM_T = 3.14 / 4;
    double sum = 0;

    vector<shared_ptr<Curve>> curve_vector;
    vector<shared_ptr<Curve>> circle_vector;
    LPGETPLUGINCURVE GetPluginFigure;
    int random_order;
    double randon_value_one;
    double random_number_two;
    int num;
    cout << "\nDISPLAYING VECTOR ELEMENTS (LENGTH 10)" << endl;
    
    for (int i = 0; i < LENGTH; i++)
    {
        num = rand() % 3 + 1;
        for (auto pluginInfo : dlls)
        {
            LPGETPLUGNAME GetPlugName = (LPGETPLUGNAME)GetProcAddress(pluginInfo.second, "GetPluginName");
            if (GetPlugName == NULL)
                continue;
        }

        HMODULE activeModule = NULL;
        for (auto pluginInfo : dlls)
        {
            if (pluginInfo.first == num)
            {
                activeModule = pluginInfo.second;
                break;
            }
        }

        if (activeModule == NULL)
        {
            std::cout << "Bad" << std::endl;
            continue;
        }
        

        GetPluginFigure = (LPGETPLUGINCURVE)GetProcAddress(activeModule, "GetPluginCurve");
        if (GetPluginFigure == NULL)
            continue;

        switch (num) {
                case 1:
                    randon_value_one = rand() % 10;
                    curve_vector.push_back(GetPluginFigure(randon_value_one,0));
                    break;
                case 2:
                    randon_value_one = rand() % 10;
                    random_number_two = rand() % 5;
                    curve_vector.push_back(GetPluginFigure(randon_value_one, random_number_two));
                    break;
                case 3:
                    randon_value_one = rand() % 10;
                    random_number_two = rand() % 5;
                    curve_vector.push_back(GetPluginFigure(randon_value_one, random_number_two));
                    break;
                }

    }

        for (auto& curve : curve_vector)
            curve->Show(curve.get(), RANDOM_T);
    
        cout << endl;
        //for (shared_ptr<Curve> curve : curve_vector)
        //{
        //    shared_ptr<Circle> circle = dynamic_pointer_cast<Circle>(curve);
        //    if (circle)
        //        circle_vector.push_back(circle);
        //}
    
        //cout << "OUTPUT OF A CONTAINER STORING ELEMENTS OF THE CIRCLE TYPE (SORTED): " << endl;
        //sort(circle_vector.begin(), circle_vector.end(), [](shared_ptr<Curve> c1, shared_ptr<Curve> c2)
        //    {
        //        return *dynamic_cast<Circle*>(c1.get()) < *dynamic_cast<Circle*>(c2.get());
        //    });
    
        //for (auto circle : circle_vector)
        //    circle->Show(circle.get(), RANDOM_T);
    
        //for (const auto& circle : circle_vector)
        //    sum += dynamic_cast<Circle*> (circle.get())->getRadius();
    
        //cout << "\nTHE TOTAL SUM OF ALL THE RADII OF THE CURVES: " << sum << endl;
    
        //for (auto dll : dlls)
        //{
        //    FreeLibrary(dll.second);
        //}
    }