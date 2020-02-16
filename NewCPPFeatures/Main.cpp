
#include <iostream>

#include "Cpp11Features.h"
#include "Cpp14Features.h"
#include "Cpp17Features.h"

int main(int argc, char **argv)
{
    
    if (argc == 2)
    {
        std::string toRun(argv[1]);
        if (toRun == "11")
        {
            Cpp11Features cpp11Features;
            cpp11Features.RunAllFeatures();
            return 1;
        }
        else if (toRun == "14") 
        {
            Cpp14Features cpp14Features;
            cpp14Features.RunAllFeatures();
            return 1;
        }
        else if (toRun == "17")
        {
            Cpp17Features cpp17Features;
            cpp17Features.RunAllFeatures();
            return 1;
        }
    }

    try 
    {
        Cpp11Features cpp11Features;
        cpp11Features.RunAllFeatures();

        Cpp14Features cpp14Features;
        cpp14Features.RunAllFeatures();

        Cpp17Features cpp17Features;
        cpp17Features.RunAllFeatures();

    }
    catch (...)
    {
        std::cout << "*** WELL, SOMETHIHNG WENT SPECTACULARLY WRONG !? **" << std::endl;

    }

}

