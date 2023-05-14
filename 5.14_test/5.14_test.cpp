#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class E
{
private:
	int _i;

public:
	E(int i)
		:_i(i)
	{
		cout << "E(int i)" << endl;
	}

	E(const E& e)
		:_i(e._i)
	{
		cout << "E(const E& e)" << endl;
	}

	E& operator=(const E& e)
	{
		cout << "E& operator=(const E& e)" << endl;
		_i = e._i;
		return *this;
	}

	~E()
	{
		cout << "~E()" << endl;
	}
};

E func1()
{
	E e(35);
	return e;
}

void func2(E e)
{

}

int main()
{
	E e1 = 41; //ͬһ���������� + �������� -> ����
	//E& e2 = 44; // wrong
	const E& e2 = 44;

	E e3 = E(48); //ͬһ���������� + �������� -> ���� 
	func2(E(52));//ͬһ���������� + �������� -> ����


	E e4 = func1(); //ͬһ�������������� + �������� -> ��������


	e1 = func1(); //ͬһ�������������� + ��ֵ���� -> ���Ż�
	e1 = E(62); //ͬһ�������������� + ��ֵ���� -> ���Ż�

	return 0;
}