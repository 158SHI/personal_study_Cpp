#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
//#include <initializer_list>
#include <list>
#include "smart_ptr.h"

using namespace std;

struct MyStruct
{
	MyStruct()
	{
		cout << "MyStruct()" << endl;
	}

	~MyStruct()
	{
		cout << "~MyStruct()" << endl;
	}

	int _i;
	char _c;
};

//delete和delete[]
void test1()
{
	//char* str = new char[10] {'1', '2'};
	//delete[] str;

	//int* pi = new int(10);
	////delete[] pi;

	//int* pa = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//delete[] pa;
	MyStruct* pa = new MyStruct[10];

	cout << *((int*)pa - 1) << endl;

	delete[] pa;
}

void test2()
{
	shr::unique_ptr<int> p1(new int(10));
	shr::unique_ptr<int> p2(new int(20));
	//p1 = p2;
}

struct Node
{
	int _d;
	shr::weak_ptr<Node> _next;
	shr::weak_ptr<Node> _prev;
};

void test3()
{
	shr::shared_ptr<Node> node1(new Node);
	shr::shared_ptr<Node> node2(new Node);
	node1->_next = node2;
	node2->_prev = node1;
}

void test4()
{
	//int a, b;
	//puts("请输入两个整数:");
	//printf("整数1:"); scanf("%d", &a);
	//printf("整数2:"); scanf("%d", &b);
	//printf("a的值是b的%.0f%%\n", ((float)a / b) * 100);
}

void test5()
{
	//pair<int, int> arrp[10] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	pair<int, int> p { 1, 3 };
	list<int> l;
}

class point
{
public:
	//explicit point(int x, int y)
	point(int x, int y)
		:_x(x), _y(y)
	{
		cout << "point" << endl;
	}

	point(const point& p)
		:_x(p._x), _y(p._y)
	{
		cout << "point(const point& p)" << endl;
	}

	//~point()
	//{
	//	cout << "~point" << endl;
	//}

private:
	int _x;
	int _y;
};

void test6()
{
	point p1(1, 3); //调用构造函数
	//point p2 = { 1, 3 }; //多参数构造函数的隐式类型转换，直接调用构造函数
	point p3{ 1, 3 }; //构造 + 拷贝构造 -> 直接构造

	list<int> l { 1, 2, 3 }; //列表初始化 initializer_list
}

class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
	{
		int m = mat.size(); int n = mat[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		vector<vector<int>> ans(m, vector<int>(n));
		//预处理前缀和矩阵
		for (int i = 1; i < m + 1; ++i)
		{
			for (int j = 1; j < n + 1; ++j)
			{
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] +
					mat[i - 1][j - 1];
			}
		}
		//使用前缀和矩阵
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		for (int i = 1; i < m + 1; ++i)
		{
			for (int j = 1; j < n + 1; ++j)
			{
				//1.确定边界
				x1 = (i - 1) - k > 0 ? i - k : 1;
				y1 = (j - 1) - k > 0 ? j - k : 1;
				x2 = (i - 1) + k < m ? i + k : m;
				y2 = (j - 1) + k < n ? j + k : n;
				//2.使用矩阵
				ans[i - 1][j - 1] =
					dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
			}
		}
		return ans;
	}
};

void test7()
{
	vector<vector<int>> mat = { {1,2,3},{4,5,6},{7,8,9} };
	Solution().matrixBlockSum(mat, 1);
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	return 0;
}