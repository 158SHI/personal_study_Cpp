#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "priority_queue.h"

using namespace std;

class add
{
public:
	int operator()(int x, int y) {
		return x + y;
	}

	int operator()(int x, int y, int z) {
		return x + y + z;
	}
};

void priority_test1()
{
	vector<int> v{ 1,4,2,6,5,1,9 };
	shr::priority_queue<int, vector<int>, shr::greater<int>> pq(v.begin(), v.begin() + v.size());
	shr::priority_queue<int> pq_s(v.begin(), v.begin() + v.size());

	pq.push(10);
	pq.push(3);
	pq.push(20);

	pq.pop();
	pq.pop();
	while (!pq.empty())
	{
		cout << pq.top() << ' ';
		pq.pop();
	}
}

class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        for (auto& str : tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int right = sT.top();
                sT.pop();
                int left = sT.top();
                sT.pop();
                char ch = str[0];
                switch (ch)
                {
                case '+':
                    sT.push(left + right);
                    break;
                case '-':
                    sT.push(left - right);
                    break;
                case '*':
                    sT.push(left * right);
                    break;
                case '/':
                    sT.push(left / right);
                    break;
                };
            }
            else {
                sT.push(stoi(str));
            }
        }
        return sT.top();
    }

private:
    stack<int> sT;
};

void test1()
{
    vector<string> tokens{ "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    Solution().evalRPN(tokens);
}

int main()
{
	//cout << add()(1, 2) << endl;
	//cout << add()(1, 2, 3) << endl;
	//priority_test1();
    test1();
	return 0;
}