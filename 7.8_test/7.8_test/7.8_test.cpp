#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        vector<int> res(2, 0);
        int key = 0;
        for (auto e : nums) {
            key ^= e;
        }
        int firstDiff = 0;
        while ((key & (1 << firstDiff)) == 0) {
            ++firstDiff;
        }
        for (auto e : nums)
        {
            if (e & (1 << firstDiff)) {
                res[0] ^= e;
            }
            else {
                res[1] ^= e;
            }
        }
        return res;
    }
};

//int main()
//{
//	vector<int> v(5, 10);
//
//	return 0;
//}

//int main(void)
//
//{
//
//    vector<int>array;
//
//    array.push_back(100);
//
//    array.push_back(300);
//
//    array.push_back(300);
//
//    array.push_back(300);
//
//    array.push_back(300);
//
//    array.push_back(500);
//
//    vector<int>::iterator itor;
//
//    for (itor = array.begin(); itor != array.end(); itor++)
//    {
//        if (*itor == 300)
//        {
//            itor = array.erase(itor);
//            //array.erase(itor);
//        }
//    }
//
//    for (itor = array.begin(); itor != array.end(); itor++)
//    {
//        cout << *itor << " ";
//    }
//    return 0;
//
//}

int main()
{
    vector<int> v{ 1, 3, 5, 7, 3, 9, 21, 3 };
    auto pos = find(v.begin(), v.end(), 3);
    while (pos != v.end())
    {
        pos = v.erase(pos);
        pos = find(pos, v.end(), 3);
    }
    return 0;
}