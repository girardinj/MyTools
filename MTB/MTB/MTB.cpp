
#include <iostream>
#include <fstream>

void help(void)
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
        "                                                \n"

    << std::endl;
}

void CountChars(std::string file_path)
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
    while (!file.eof())
    {
        file.get(c);
        ++i;
    }
    // because eof is added
    --i;
    file.close();
    std::cout << "There is " << i << " characters in the file " << file_path << std::endl;
}

void readFile(std::string file_path)
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

void infoFile(std::string file_path)
{

}

int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        help();
        return 0;
    }
    std::string param = argv[1];

    if (param == "-cc")
    {
        if (argc <= 2)
        {
            std::cout << "missing argument" << std::endl;
            return 0;
        }
        CountChars(argv[2]);
        return 0;
    } else if (param == "-r")
    {
        if (argc <= 2)
        {
            std::cout << "missing argument" << std::endl;
            return 0;
        }
        readFile(argv[2]);
        return 0;
    } else if (param == "-info")
    {
        if (argc <= 2)
        {
            std::cout << "missing argument" << std::endl;
            return 0;
        }
        infoFile(argv[2]);
        return 0;
    }
    help();
    return 0;
}
