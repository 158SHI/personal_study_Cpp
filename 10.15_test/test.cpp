#define _CRT_SECURE_NO_WARNINGS 1

#include "smart_ptr.h"
#include "unNormalClass.h"
#include <iostream>
#include <vector>

using namespace std;

class Demo
{
public:
	Demo(int i = 0)
		:_i(i)
	{
		cout << "Demo()" << endl;
	}

	void print()
	{
		cout << "_i = " << _i << endl;
	}

	~Demo()
	{
		cout << "~Demo()" << endl;
	}

private:
	int _i;
};

//unique_ptr
void test1()
{
	//shr::unique_ptr<Demo> up(new Demo(10), [](Demo* p) {delete p; });
	shr::unique_ptr<Demo> up(new Demo(10));
	//shr::unique_ptr<Demo> up2(new Demo[10], [](Demo* p) { delete[] p; });
	//shr::unique_ptr<Demo> up2(new Demo[10]);
	//shr::unique_ptr<Demo> up2(up);
	up->print();
	//shr::unique_ptr<FILE> up3(fopen("test.txt", "r"), [](FILE* pf) { fclose(pf); });
}

//shared_ptr
void test2()
{
	shr::shared_ptr<Demo> sp(new Demo[10], [](Demo* p) { delete[] p; });
	shr::shared_ptr<Demo> sp2(new Demo[10], [](Demo* p) { delete[] p; });
	sp = sp2;
	shr::shared_ptr<Demo> sp3(sp);
	//sp->print();
	//sp2->print();
	//sp.~shared_ptr();
	shr::shared_ptr<Demo> sp4;
	shr::shared_ptr<Demo> sp5(sp4);
	sp5 = sp3;

	int x = 10;
}

struct node
{
	shr::weak_ptr<node> _prev;
	shr::weak_ptr<node> _next;

	//shr::shared_ptr<node> _prev;
	//shr::shared_ptr<node> _next;
};

//weak_ptr���ѭ������
void test3()
{
	shr::shared_ptr<node> first(new node);
	shr::shared_ptr<node> second(new node);
	first->_next = second;
	second->_prev = first;

	//first.~shared_ptr();
	//second.~shared_ptr();

	int x = 10;
}

class demo2
{
public:
	demo2()
	{
		cout << "demo2()" << endl;
	}

	~demo2()
	{
		cout << "~demo2()" << endl;
		delete this;
	}

private:

};

//�������������
void test4()
{
	//new�����Ķ��󲻻�������������
	Demo* p = new Demo();
	demo2* pd = new demo2;
	demo2 d; //����ʱ��ѭ��
	pd->~demo2(); //��ѭ��
}

//���������
void test5()
{
	ClassStack objSt1 = ClassStack::getObjectStack();
	//ClassStack* pObjSt = new ClassStack(objSt1); //new���ÿ�������,������

	//ClassHeap ch;
	//static ClassHeap ch;
	ClassHeap* pch = new ClassHeap;
	pch->Destroy(); //��Ҫ�ṩ��Դ�ͷŽӿ�

	ClassHeap2* pch2 = ClassHeap2::getObjHeap();
	//ClassHeap2* pch3 = new ClassHeap2;
	//ClassHeap2 ch(*pch2); //���ÿ������죬������
	//static ClassHeap2 ch;
	pch2->~ClassHeap2();

	ClassNoCopy cnp1;
	//ClassNoCopy cnp2(cnp1);
	ClassNoCopy cnp2;
	//cnp1 = cnp2;

	cout << &(Hungry::getInstance()) << endl;
	cout << &(Hungry::getInstance()) << endl;
	cout << &(Hungry::getInstance()) << endl;

	cout << Hungry::getInstance().get() << endl;
	Hungry::getInstance().set(10);
	cout << Hungry::getInstance().get() << endl;
	cout << &(Hungry::getInstance()) << endl;

	//Lazy* lzObj = Lazy::getLzObj();
	cout << &(Lazy::getLzObj()) << endl;
	cout << &(Lazy::getLzObj()) << endl;
	cout << &(Lazy::getLzObj()) << endl;
	cout << Lazy::getLzObj().get() << endl;
	Lazy::getLzObj().set(10);
	cout << Lazy::getLzObj().get() << endl;
	Lazy::getLzObj().Destroy();
}

class father
{
public:
	virtual void vfunc()
	{
		cout << "father::vfunc()" << endl;
	}

private:

};

class child : public father
{
public:

private:

};

//C++����ת����׼
void test6()
{
	//static_cast
	//����������֮���ת��
	int i1 = 10;
	double d1 = static_cast<double>(i1);
	cout << d1 << endl;
	double d2 = 3.14159;
	int i2 = static_cast<int>(d2);
	cout << i2 << endl;

	//reinterpret_cast
	//��Բ��������֮���ת��
	int* p1 = &i1;
	i2 = reinterpret_cast<int>(p1);
	//i2 = (int)p1;
	cout << i2 << endl;
	
	//const_cast
	//���ȥ��const���Ե�ת��
	//const int ci1 = 10;
	volatile const int ci1 = 10;
	volatile double cd1 = 3.14;
	//int* pci1 = (int*)&ci1; //ȥ��������const�����ǲ���ȫ��
	int* pci1 = const_cast<int*>(&ci1);
	//volatile int* pci2 = (int*)(double*)&cd1;
	*pci1 = 20;
	//*pci2 = 5;
	cout << ci1 << endl;
	cout << *pci1 << endl;
	//cout << "cd = " << cd1 << endl;
	//cout << "*pci2 = " << *pci2 << endl;

	//dynamic_cast
	//�ڼ̳���ϵ�У��������ת��������ת��
	father* pf = new father;
	//child* pc = new child;
	//father* pf = dynamic_cast<father*>(pc);
	
	//dynamic_cast�Ĳ����������Ƕ�̬����(�����麯����)
	child* pc = dynamic_cast<child*>(pf); 
	child* pc2 = new child;
	cout << pf << endl;
	cout << pc << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test6();
	return 0;
}