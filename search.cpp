#include <iostream>
#include <vector>
#include <string>
#include "functions.h"
std::vector<std::string> searchWords(std::vector<std::string> &words, std::string query)
{
    std::vector<std::string> results;

    for (size_t i = 0; i < words.size(); i++)
    {
        if (words[i].size() == query.size())
        {
            int count = 0;
            for (size_t j = 0; j < query.size(); j++)
            {
                if (words[i][j] == query[j] || query[j] == '*')
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (count == query.size())
            {
                results.push_back(words[i]);
            }
        }
    }
    return results;
}