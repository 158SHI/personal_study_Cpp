#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<string>& words)
    {
        static const string rowIndex("12210111011122000010020202");
        vector<string> res;
        for (auto& word : words)
        {
            bool flag = true;
            for (auto it = word.begin() + 1; it != word.end(); ++it)
            {
                char ch = *it, preCh = *(it - 1);
                if (rowIndex[tolower(ch) - 'a'] != rowIndex[tolower(preCh) - 'a'])
                {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(word);
            }
        }
        return res;
    }
};

int main()
{
    vector<string> v{"Hello", "Alaska", "Dad", "Peace"};

    Solution().findWords(v);
    return 0;
}