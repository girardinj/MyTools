#include "mtb.h"
#include <iostream>
#include "ENUM_PARAMS.h"

void f_debug(int &argc, char** &argv) {
    argc = 2;
    char var[] = "hi";
    char* c = argv[0];

    argv = new char*[argc];

    argv[0] = c;
    argv[1] = var;
}

bool isInt(std::string s) {
    for (char c : s) {
        if (!std::isdigit((int)c))
            return false;
    }
    return true;
}

int main(int argc, char** argv)
{
    //f_debug(argc, argv);

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
        {
            if (argc >= 4)
            {
                std::string s1 = argv[ 2 ];
                std::string s2 = argv[ 2 ];
                if (s1 == "-f" || s1 == "-F")
                {
                    MTB::taskKill(argv[ 3 ], true);
                    break;
                } else if (s2 == "-f" || s2 == "-F")
                {
                    MTB::taskKill(argv[ 2 ], true);
                    break;
                }
            }
            MTB::taskKill(argv[ 2 ], false);
            break;
        }

        // -delay
        case DELAY: {
            char *ptr = nullptr;
            if (!isInt(argv[2])) {
                std::cout << "Time is invalid, use whole positive numbers !" << std::endl;
                break;
            }

            MTB::delay(argv[3], atoi(argv[2]));
            break;
        }
        // -test
        case TEST:
            MTB::test();
            break;

        // default
        default:
            MTB::help();
            break;
    }
    return 0;
}
