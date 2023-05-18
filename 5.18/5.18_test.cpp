#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//class A
//{
//private:
//	int _i;
//
//public:
//	A(int i = 10)
//		:_i(i)
//	{ }
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//int main()
//{
//	//int* a = new int;
//	//int* b = (int*)operator new(sizeof(int));
//
//	//delete a;
//	//delete b;
//
//	A* pA = new A;
//	delete pA;
//
//	A* pClockA = (A*)operator new(sizeof(A) * 10);
//
//	A* pA1 = new(pClockA) A(1); //replacement-new
//	A* pA2 = new(pClockA + 1) A(2);
//	pA1->~A();
//	pA2->~A();
//
//	return 0;
//}

class A
{
private:
	int _i;

public:
	A(int i = 10)
		:_i(i)
	{
		cout << "A(int i)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
};

void test1()
{
	//内置类型
	int* pI1 = new int;
	delete pI1;

	double* pD1 = new double(3.14);
	delete pD1;
	//自定义类型
	int* pArr1 = new int[10];
	delete[] pArr1;

	int* pArr2 = new int[10] { 1, 2, 3 };
	delete[] pArr2;
	//类
	A* pA = new A(20);
	delete pA;
	cout << "test" << endl;
}

void test2()
{
	A* pA = (A*)operator new(sizeof(A));
	operator delete(pA);
}

void test3()
{
	A* pA = new A;
	delete pA;
}

void test4()
{
	A* pA = (A*)operator new(sizeof(A) * 10);
	new(pA)A[3]{ 1, 2 };
	operator delete(pA);
}

int main()
{
	//test1();
	//test3();
	test4();
	return 0;
}


//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
//
//
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}
//#define free(p) _free_dbg(p, _NORMAL_BLOCK)