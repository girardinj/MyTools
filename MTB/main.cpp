#include "mtb.h"
#include <iostream>
#include "ENUM_PARAMS.h"


int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        MTB::help();
        return 0;
    }

    switch(getParam(argc, argv)) {

        // not enough arguments
        case INVALID_NUMBER_ARGUMENT:
            std::cout << "Number of arguments invalid, try more :)" << std::endl;
            break;

        // -h
        case HELP:
            MTB::help();
            break;

        // -r
        case FILE_READ:
            MTB::file_read(argv[ 2 ]);
            break;

        // -cc
        case FILE_COUNT_CHAR:
            MTB::file_countChars(argv[ 2 ]);
            break;

        // -cl
        case FILE_COUNT_LINE:
            MTB::file_countLines(argv[ 2 ]);
            break;

        // -info
        case FILE_GET_INFO:
            MTB::file_info(argv[ 2 ]);
            break;

        // -tk
        case TASK_KILL:
            MTB::taskKill(argv[2]);
            break;

        // default
        default:
            MTB::help();
            break;
    }
    return 0;
}