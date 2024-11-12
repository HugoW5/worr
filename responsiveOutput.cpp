#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

void printResponsive(CONSOLE_SCREEN_BUFFER_INFO &consoleInfo, std::vector<std::string> &words)
{
    std::cout << "Console Width: " << consoleInfo.dwSize.X << std::endl;
}