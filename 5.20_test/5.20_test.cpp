#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>

using namespace std;

//template<typename T1, typename T2> //定义多个模板参数
//T1 Add(T1 a, T2 b)
//{
//	return a + b;
//}

//template<typename T1, typename T2>
//T1 Add(const T1& a, const T2& b)
//{
//	return a + b;
//}
//
//int Add(const int& a, const int& b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int i1 = 10;
//	int i2 = 20;
//	double d1 = 3.14;
//	double d2 = 5.12;
//	//与非模板函数类型完全匹配，直接调用非模板函数而不需要函数模板实例化
//	Add(i1, i2); 
//	//函数模板可以生成类型更加匹配的函数，调用实例化出的函数
//	Add(i1, d2);
//	return 0;
//}


//template<typename T> //定义单个模板参数
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int i1 = 10, i2 = 20;
//	//double d1 = 3.14, d2 = 5.12;
//	Swap(i1, i2); //与非模板参数类型匹配，编译器不需要进行实例化
//	Swap<int>(i1, i2); //显式实例化，调用实例化后的模板函数
//	return 0;
//}

template<typename T>
class Vector
{
private:
	T* _pData;
	size_t _size;
	size_t _capacity;

public:
	Vector(size_t capacity = 10)
		:_pData(new[capacity]),
		_size(0),
		_capacity(capacity)
	{ }

	/*...*/
	
	T operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}

	~Vector()
	{
		if (_pData) {
			delete[] _pData;
		}
		_size = _capacity = 0;
	}
};

int main()
{
	Vector<int> v;
	
	return 0;
}