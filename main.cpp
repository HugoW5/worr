#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include "functions.h"

using namespace std;
void readFile(string path, vector<string> &words);

int main()
{
    // Get Standart output (Console Handle)
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    // Get console buffer for use in responsive output
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

    // Enable UTF-8 Encoding
    SetConsoleOutputCP(CP_UTF8);
    vector<string> words;
    readFile("words.txt", words);
    string userInput;
    while (true)
    {
        SetConsoleTextAttribute(hStdout, 0x006);
        cout << "Asterisk (*) representerar okänt tecken\n";
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
        // Update the consoleInfo
        GetConsoleScreenBufferInfo(hStdout, &consoleInfo);
        cout << "Hittade " << results.size() << " resultat\n";
        // Print results
        // Foreground color cyan
        SetConsoleTextAttribute(hStdout, 0x0003);

        if (results.size() > 50)
        {
            printResponsive(consoleInfo, results);
        }
        else
        {
            for (size_t i = 0; i < results.size(); i++)
            {
                cout << results[i] << "\n";
            }
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