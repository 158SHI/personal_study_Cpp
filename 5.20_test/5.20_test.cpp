#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>

using namespace std;

//template<typename T1, typename T2> //������ģ�����
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
//	//���ģ�庯��������ȫƥ�䣬ֱ�ӵ��÷�ģ�庯��������Ҫ����ģ��ʵ����
//	Add(i1, i2); 
//	//����ģ������������͸���ƥ��ĺ���������ʵ�������ĺ���
//	Add(i1, d2);
//	return 0;
//}


//template<typename T> //���嵥��ģ�����
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
//	Swap(i1, i2); //���ģ���������ƥ�䣬����������Ҫ����ʵ����
//	Swap<int>(i1, i2); //��ʽʵ����������ʵ�������ģ�庯��
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