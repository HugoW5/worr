#include <iostream>
#include <string>
#include <vector>   
#include <Windows.h>
#include <iomanip>

void printResponsive(CONSOLE_SCREEN_BUFFER_INFO &consoleInfo, std::vector<std::string> &words)
{
    //print words
    int offset = 0;
    for (size_t i = 0; i < words.size(); i++)
    {
        offset += words[i].length() + 4;

        if (offset > consoleInfo.dwSize.X)
        {
            offset = 0;
            std::cout << '\n';
        }
        std::cout << words[i] << "   ";
    }
    std::cout << std::endl;
}