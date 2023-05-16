#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

class A
{
private:
	int _i;

public:
	A(int i = 10)
		:_i(i)
	{ }

	~A()
	{

	}
};

void test1()
{
	int* p1 = new int;
	delete p1;

	int* pArr1 = new int[10] { 0 };
	for (int i = 0; i < 10; i++) {
		cout << pArr1[i] << ' ' ;
	}
	delete[] pArr1;

	A* pA = new A(1);
	delete pA;

	A* pArrA1 = new A[5]{ A(1), A(2), A(3) };
	A* pArrA2 = new A[5]{ 1, 2, 3 };
	delete[] pArrA1;
	delete[] pArrA2;
}

int main()
{
	//A a;
	//a.~A();
	//try
	//{
	//	A* pA = (A*)operator new(sizeof(A) * 5);
	//	A* a = new(pA)A(1);
	//	A* b = new(pA + 1)A(2);
	//	a->~A();
	//	b->~A();
	//}
	//catch (const exception& e)
	//{
	//	cout << e.what() << endl;
	//}
	test1();
	return 0;
}