#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"
#include "queue.h"
#include <stack>
#include <iostream>

using namespace std;

void stack_test1()
{
	//shr::stack<int, vector<int>> sT;
	shr::stack<int> sT;
	sT.push(1);
	sT.push(2);
	sT.push(3);
	sT.push(4);

	while (!sT.empty()) {
		cout << sT.top() << ' ';
		sT.pop();
	}
	cout << endl;
}

void queue_test1()
{
	shr::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}
}

class Solution {
public:
	bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
	{
		int pushI = 0, popI = 0;
		while (pushI < pushV.size())
		{
			sT.push(pushV[pushI++]);
			while (!sT.empty() && sT.top() == popV[popI])
			{
				sT.pop();
				++popI;
			}
		}
		return sT.empty();
	}

private:
	stack<int> sT;
};

int main()
{
	//stack_test1();
	//queue_test1();
	vector<int> v1{ 1,2,3,4,5 };
	vector<int> v2{ 4,5,3,2,1 };
	Solution().IsPopOrder(v1, v2);
	return 0;
}