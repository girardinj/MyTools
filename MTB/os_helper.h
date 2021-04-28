//
// Created by girar on 28.04.2021.
//

#pragma once
#include <sstream>
#include <vector>

class OSHelper
{
public:
    static std::istringstream getTasks(std::string taskName);
    static std::string execTaskKill(std::string task_name, bool shouldForce);

    static bool isOSError();
    static const std::string osNotSupported;

private:
    static bool OSError;
    static std::string exec(std::string command);
    static void setOSError(bool b);
};



