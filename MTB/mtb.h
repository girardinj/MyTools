//
// Created by girar on 28.04.2021.
//

#pragma once
#include <string>

// static class !
class MTB {

public:
    static void help();
    static void file_countChars(std::string file_path);
    static unsigned int countChar(std::ifstream &file);
    static void file_countLines(std::string file_path);
    static void file_read(std::string file_path);
    static void file_info(std::string file_path);
    static void taskKill(std::string task_name);

private:
    static std::string exec(std::string command);
    static std::string getFirstWord(std::string line, int size);
};
