#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include "function.h"

using namespace std;
void readFile(string path, vector<string> &words);

int main()
{
    
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN);
    SetConsoleOutputCP(CP_UTF8);
    vector<string> words;
    readFile("words2.txt", words);
    searchWords(words);
    cout << words.size() << endl;

    for (size_t i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }
    cout << "åäö" << endl;

    string input;
    cin >> input;
    return 0;
}

void readFile(string path, vector<string> &words)
{
    ifstream fs(path);
    string line;
    while (getline(fs, line))
    {
        words.push_back(line);
    }
    fs.close();
}