//
// Created by girar on 28.04.2021.
//

#pragma once

enum PARAMS {
    DEFAULT,
    INVALID_NUMBER_ARGUMENT,
    HELP,
    FILE_READ,
    FILE_COUNT_CHAR,
    FILE_COUNT_LINE,
    FILE_GET_INFO,
    TASK_KILL,
    DELAY,
    TEST
};

int getParam(int argc, char** argv) {
    std::string param = argv[1];

    if (param == "-h")
        return HELP;
    if (param == "-test")
        return TEST;

    // from now, we need (at least) two arguments
    if (argc < 3)
        return INVALID_NUMBER_ARGUMENT;

    if (param == "-r")
        return FILE_READ;
    if (param == "-cc")
        return FILE_COUNT_CHAR;
    if (param == "-cl")
        return FILE_COUNT_LINE;
    if (param == "-info")
        return FILE_GET_INFO;
    if (param == "-tk")
    {
        std::string force = argv[2];
        if ((force == "-f" || force == "-F") && argc < 4)
            return INVALID_NUMBER_ARGUMENT;
        return TASK_KILL;
    }

    if (argc < 4)
        return INVALID_NUMBER_ARGUMENT;

    if (param == "-delay")
        return DELAY;

    return DEFAULT;
}