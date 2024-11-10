#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;
void readFile(string path, vector<string> &words);

int main()
{
    
    vector<string> words;
    readFile("words2.txt", words);
    cout << words.size() << endl;
 
    for(size_t i = 0; i < words.size(); i++){
        cout << words[i] << endl;
    }
    return 0;
}

void readFile(string path, vector<string> &words)
{
    locale loc (locale(), new codecvt_utf8<char32_t>); // declare encoding
    ifstream fs(path);
    fs.imbue(loc); //set encoding to UTF-8
    string line;
    while (getline(fs, line))
    {
        cout << line << endl;
        words.push_back(line);
    }
    fs.close();
}