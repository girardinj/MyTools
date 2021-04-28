#include "mtb.h"

#include <iostream>
#include <fstream>

void MTB::help()
{
    std::cout <<
              "                                                \n"
              "          MTB (MyToolBox) by Jarod Corp.        \n"
              "                                                \n"
              "                     -+sso-                     \n"
              "               :shdhhd+--+ddshdhs-              \n"
              "          `/osdm/` ./      y/` .+Nyso:          \n"
              "         +Ns:-:`                 .:-/hN:        \n"
              "        .Mo                           hN        \n"
              "      -ymy/                           oNy-      \n"
              "     .Ms         +Ns-.+mm+.-sNo         sN.     \n"
              "     :M:  -shhdddd++yyo--oyy+/hddddhyo. :M:     \n"
              "     -Nd` +Mo`                     `yM-`dN-     \n"
              "    `Ny    /ydddo +ss/    /ss/ oddddy-   yN`    \n"
              "    `Ny        oM-`//`    `//`-M+        yN`    \n"
              "     -dd.       dm`          `md       .dd-     \n"
              "      sM`       .Nh          hN.       `Ms      \n"
              "      .md:`      -Nh` -++- `hN-      `:dm.      \n"
              "        /hM:      .dd--++--dd.      :Mh/        \n"
              "         -Ms        +mh++hm+        sM.         \n"
              "          -hmyy/      -//-      /yymh-          \n"
              "             ./mho+oy      yo+ohm/.             \n"
              "                .//:dd+--+dd://.                \n"
              "                     -osso-                     \n"
              "                                                \n"
              "                                                \n"
              " -r  FILE_PATH  read file in prompt             \n"
              " -cc FILE_PATH  count chars number of the file  \n"
              " -cl FILE_PATH  count lines number of the file  \n"
              " -info FILE_PATH  gives some informations about the file\n"
              " -tk TASK_NAME  find task and kill it           \n"
              "                                                \n"

              << std::endl;
}

void MTB::file_countLines(std::string file_path)
{
    std::ifstream file;
    file.open(file_path, std::ios::in | std::ios::binary);
    if (!file.good())
    {
        std::cout << "Error with the file name" << std::endl;
        return;
    }
    unsigned int i = 0;
    char c;
    bool thereWasALine = false;

    while (!file.eof())
    {
        if (!thereWasALine) {
            thereWasALine = true;
            ++i;
        }

        file.get(c);

        if (c == '\n')
        {
            thereWasALine = false;
        }
    }

    file.close();

    std::string isEmpty = "";
    std::string s = "s";

    std::ifstream file2;
    file2.open(file_path, std::ios::in | std::ios::binary);

    if (countChar(file2) == 0)
        isEmpty = " (empty file)";
    if (i == 0 || i == 1)
        s = "";

    file2.close();

    std::cout << "There is " << i << " line" << s << " in the file " << file_path << isEmpty << std::endl;
}

void MTB::file_countChars(std::string file_path)
{
    std::ifstream file;
    file.open(file_path, std::ios::in | std::ios::binary);
    if (!file.good())
    {
        std::cout << "Error with the file name" << std::endl;
        return;
    }
    unsigned int i = countChar(file);

    file.close();

    std::string s = "s";
    if (i == 0 || i == 1)
        s = "";

    std::cout << "There is " << i << " character" << s << " in the file " << file_path << std::endl;
}

unsigned int MTB::countChar(std::ifstream &file)
{
    unsigned int i = 0;
    char c;
    while (!file.eof())
    {
        file.get(c);
        ++i;
    }
    // because eof is added
    --i;
    return i;
}

void MTB::file_read(std::string file_path)
{
    std::ifstream file;
    file.open(file_path, std::ios::in);
    if (!file.good())
    {
        std::cout << "Error with the file name" << std::endl;
        return;
    }
    std::cout << file_path << " :" << std::endl;
    std::cout << "-------------------------------- " << std::endl;
    while (!file.eof())
    {
        char c;
        file.get(c);
        std::cout << c;
    }
    file.close();
}

void MTB::file_info(std::string file_path) {
    std::cout << "one day..." << std::endl;
}

void MTB::taskKill(std::string task_name) {

}
