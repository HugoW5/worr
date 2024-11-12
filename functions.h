// functions.h
#include <Windows.h>
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/// @brief Searches the words vector : string
/// @param words Vector with the words : string
/// @param query The specified word search query
/// @return Vector<string> with the results
std::vector<std::string> searchWords(std::vector<std::string> &words, std::string query);
/// @brief Prints out the results responsive
/// @param consoleInfo CONSOLE_SCREEN_BUFFER_INFO
/// @param words vector:string with words
void printResponsive(CONSOLE_SCREEN_BUFFER_INFO &consoleInfo, std::vector<std::string> &words);
#endif