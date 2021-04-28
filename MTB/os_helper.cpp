//
// Created by girar on 28.04.2021.
//

#include "os_helper.h"

const std::string OSHelper::osNotSupported = "sorry OS not supported";
bool OSHelper::OSError = false;

std::istringstream OSHelper::getTasks(std::string taskName) {
    setOSError(false);
#ifdef _WIN32
    return std::istringstream(exec("tasklist | findstr " + taskName));
#elif __linux__
    return std::istringstream();
#else
    setOSError(true);
    return std::istringstream();
#endif
}

std::string OSHelper::execTaskKill(std::string task_name, bool shouldForce) {
    setOSError(false);

    std::string ret;
#ifdef _WIN32
    ret = (exec("tasklist | findstr " + task_name));
#elif __linux__
    // TODO
    std::cout << "implement in linux plz" << std::endl;
    ret = "";
#else
    setOSError(true);
#endif
    return ret;
}

// https://www.tutorialspoint.com/How-to-execute-a-command-and-get-the-output-of-command-within-Cplusplus-using-POSIX
std::string OSHelper::exec(std::string command) {
    char buffer[128];
    std::string result = "";

    // Open pipe to file
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return "popen failed!";
    }

    // read till end of process:
    while (!feof(pipe)) {

        // use buffer to read and add to result
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }

    pclose(pipe);
    return result;
}
void OSHelper::setOSError(bool b)
{
    OSError = b;
}

bool OSHelper::isOSError()
{
    return OSError;
}
