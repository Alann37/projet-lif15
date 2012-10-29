#include "automate.h"

#include <iostream>

bool Automate::readfile(const char* filename)
{
    FILE** file;
    if(fopen_s(file, filename,"R"))
    {
        return true;
    }
    else
        return false;
}
