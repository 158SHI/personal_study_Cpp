#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        int len = words[0].size(); //单词长度
        unordered_map<string, int> wordsMap;
        unordered_map<string, int> wordsCur;
        for (const auto& word : words) {
            wordsMap[word]++;
        }
        vector<int> res;
        for (int i = 0; i < len; ++i)
        {
            int left = i, right = i;
            wordsCur.clear();
            int count = 0; //记录有效元素个数
            while (right + len <= s.size())
            {
                string strCur = s.substr(right, len);
                wordsCur[strCur]++; //进窗口
                if (wordsCur[strCur] <= wordsMap[strCur]) {
                    ++count; //更新有效元素个数
                }

                if ((right - left) / len + 1 == words.size())
                {
                    if (count == words.size()) {
                        res.push_back(left); //更新结果
                    }
                    //出窗口
                    string strLeft = s.substr(left, len);
                    if (wordsCur[strLeft] <= wordsMap[strLeft]) {
                        --count; //更新有效元素个数
                    }
                    wordsCur[strLeft]--;
                    left += len;
                }
                right += len;
            }
        }
        return res;
    }
};

void test1()
{
    string s("barfoothefoobarman");
    vector<string> v{ "foo","bar" };
    vector<int> ret = Solution().findSubstring(s, v);
}

int main()
{
    test1();
    return 0;
}