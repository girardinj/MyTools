#include "mtb.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>

#include "os_helper.h"

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
              " -tk (-f) TASK_NAME  find task and kill it (-f to auto force it\n"
              " -delay MINUTES APP delay the execution of a specified app in minutes\n"
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

// https://stackoverflow.com/questions/5059049/read-a-string-line-by-line-using-c
void MTB::taskKill(std::string taskName, bool isForced) {
    int i = 0;

    std::istringstream execRet = OSHelper::getTasks(taskName);
    if (OSHelper::isOSError()) {
        std::cout << OSHelper::osNotSupported << std::endl;
        return;
    }

    std::string line;
    std::vector<std::string> listString;

    while(std::getline( execRet, line)) {
        std::cout << "[" << i++ << "] " << line << std::endl;
        listString.push_back(line);
    }
    if (listString.size() == 0) {
        std::cout << "no task found..." << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << "/!\\ Do not choose one with spaces ! (like Hunt Game.exe) /!\\" << std::endl;
    std::cout << "Which one to delete ? (-1 to quit)" << std::endl;
    bool isDigit = false;
    int index;
    while (!isDigit)
    {
        std::string indexToDelete;
        std::cin >> indexToDelete;

        isDigit = true;

        for (int c = 0; c < indexToDelete.size(); ++c)
        {
            if (!isdigit(indexToDelete[ c ]))
            {
                if (c == 0 && indexToDelete[ c ] == '-')
                {
                    continue;
                }
                isDigit = false;
                break;
            }
        }
        if (isDigit) {
            index = std::stoi(indexToDelete);
            // must cast size to int (was uint I guess) to have -1 to pass the test
            if (index < -1 || index >= (int)listString.size())
                isDigit = false;
        }
        if (!isDigit) {
            std::cout << "Enter valid number or -1 to quit" << std::endl;
        }
    }

    if (index == -1) {
        std::cout << "exiting without killing anybody..." << std::endl;
        return;
    }

    // https://stackoverflow.com/questions/43972500/how-to-only-accept-y-or-n-in-users-input-in-c
    char c = 0;
    if (isForced)
        c = 'y';
    else
        while (true)
        {
            std::cout << "Should force it? (y/n) ";
            std::cin >> c;
            c = tolower(c);
            if (c == 'y' || c == 'n')
                break;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    bool shouldForce = (c == 'Y' || c == 'y');

    std::string toExec = OSHelper::execTaskKill(getFirstWord(listString.at(index), listString.at(index).size()), shouldForce);
    if (OSHelper::isOSError()) {
        std::cout << OSHelper::osNotSupported << std::endl;
        return;
    }
    std::cout << toExec << std::endl;

}

// https://www.tutorialspoint.com/How-to-execute-a-command-and-get-the-output-of-command-within-Cplusplus-using-POSIX
std::string MTB::exec(std::string command) {
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

std::string MTB::execInNewWindow(std::string command) {
#ifdef _WIN32
    return exec("start " + command);
#endif
}

// https://stackoverflow.com/questions/16029324/splitting-a-string-into-an-array-in-c-without-using-vector
std::string MTB::getFirstWord(std::string line, int size){
    std::string arr[size];
    int i = 0;
    std::stringstream ssin(line);
    while (ssin.good() && i < size) {
        // who cares about the rest, only need the first
        ssin >> arr[i];
        ++i;
    }

    return arr[0];
}

void MTB::delay(std::string appWithParam, unsigned int time) {
    // minutes
    while (time > 1) {
        std::string toPrint = "sleeping for " + std::to_string(time--) + " minutes";
        std::cout << toPrint << std::endl;
        OSHelper::sleep(60 * 10*10*10);
        /*
        std::cout << "\r";
        for (int i = 0; i < toPrint.length(); ++i)
            std::cout << " ";
        std::cout << "\r";
         */
    }
    std::cout << std::endl;

    time = 60;
    // secondes
    while (time > 0) {
        std::string toPrint = "sleeping for " + std::to_string(time) + " seconde";
        if (time > 1)
            toPrint += "s";
        std::cout << toPrint << std::endl;
        --time;
        //OSHelper::sleep(10*10*10);
        OSHelper::sleep(1);

        /*
        std::cout << "\r";
        for (int i = 0; i < toPrint.length(); ++i)
            std::cout << " ";
        std::cout << "\r";
         */
    }
    std::cout << std::endl;
    std::cout << "executing " << appWithParam << std::endl;
    execInNewWindow(appWithParam);
}

void MTB::test(){
    std::cout << "bonjour, je suis un joli test, comment allez-vous ?" << std::endl;
}