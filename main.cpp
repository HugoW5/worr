#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include "search.h"

using namespace std;
void readFile(string path, vector<string> &words);

int main()
{
    // Get Standart output (Console Handle)
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    // Enable UTF-8 Encoding
    SetConsoleOutputCP(CP_UTF8);
    vector<string> words;
    readFile("words.txt", words);
    string userInput;
    while (true)
    {
        SetConsoleTextAttribute(hStdout, 0x006);
        cout << "Asterisk (*) representerar okänt tecken" << endl;
        cout << "Ord: ";
        cin >> userInput;
        vector<string> results = searchWords(words, userInput);
        if (results.size() > 0)
        {
            SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN);
        }
        else
        {
            SetConsoleTextAttribute(hStdout, FOREGROUND_RED);
        }
        cout << "Hittade " << results.size() << " resultat" << endl;
        // Print results
        // Foreground color cyan
        SetConsoleTextAttribute(hStdout, 0x0003);
        for (size_t i = 0; i < results.size(); i++)
        {
            cout << results[i] << endl;
        }
    }
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