#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//ջ�ϵ���
class ClassStack
{
public:
	static ClassStack getObjectStack()
	{
		ClassStack newObj;
		return newObj;
	}

	//new == operator new + copyConstructor/constructor
	//��ֹ����new, ΪClassStack����ר��operator new
	void* operator new(size_t size) = delete;

private:
	//���캯��˽�л�
	ClassStack()
	{
		cout << "ClassStack()" << endl;
	}
};

//���ϵ���
class ClassHeap
{
public:
	ClassHeap()
	{
		cout << "ClassHeap" << endl;
	}

	//��Դ�ͷŽӿ�
	void Destroy()
	{
		delete this;
	}

private:
	//��������˽�л�
	~ClassHeap()
	{
		cout << "~ClassHeap()" << endl;
	}
};

//���ϵ���_2
class ClassHeap2
{
public:
	static ClassHeap2* getObjHeap()
	{
		ClassHeap2* pCh = new ClassHeap2;
		return pCh;
	}

	~ClassHeap2()
	{
		cout << "~ClassHeap2()" << endl;
	}

	ClassHeap2(const ClassHeap2& ch2) = delete;

private:
	//���캯��˽�л�
	ClassHeap2()
	{
		cout << "ClassHeap2()" << endl;
	}
};

//���ܱ���������
class ClassNoCopy
{
public:
	ClassNoCopy()
	{
		cout << "ClassNoCopy" << endl;
	}

	~ClassNoCopy()
	{
		cout << "~ClassNoCopy()" << endl;
	}

	ClassNoCopy(const ClassNoCopy& cnp) = delete;
	ClassNoCopy& operator=(const ClassNoCopy& cnp) = delete;

private:

};

////����ģʽ
//����ģʽ
//��main����֮ǰ�ͽ��й���
class Hungry
{
public:
	//3.��ȡ����ʵ��
	static Hungry& getInstance()
	{
		return _huObj;
	}

	//4.�ṩ�����ӿ�
	void set(int a)
	{
		_a = a;
	}

	int get()
	{
		return _a;
	}

	~Hungry()
	{
		cout << "~Hungry()" << endl;
	}

	//5.���ÿ���
	Hungry(const Hungry& huObj) = delete;
	Hungry& operator=(const Hungry& huObj) = delete;

private:
	//2.���캯��˽��
	Hungry(int a)
	{
		cout << "Hungry()" << endl;
	}

private:
	//1.��̬���Ա
	static Hungry _huObj;
	int _a;
};

Hungry Hungry::_huObj(0); //ֱ��ʵ������һ������

//����ģʽ
//��һ��ʹ�õ�ʱ��Ź������
class Lazy
{
public:
	//��ȡ����ӿ�
	static Lazy& getLzObj()
	{
		if (_lzObj == nullptr) {
			_lzObj = new Lazy;
		}
		return *_lzObj;
	}

	//3.�ṩ�����ӿ�
	void set(int a)
	{
		_a = a;
	}

	int get()
	{
		return _a;
	}

	//4.�ṩ�����ͷŽӿ�
	//���� ��;��ʾ�ͷ� ����
	//��һЩ���⶯��(�־û���)
	void Destroy()
	{
		//�������������Խ���һЩ���⶯��
		delete this;
	}

	//5.���ÿ���
	Lazy(const Lazy& lz) = delete;
	Lazy& operator=(const Lazy& lz) = delete;

private:
	//2.���������˽�л�
	Lazy()
	{
		cout << "Lazy()" << endl;
	}

	~Lazy()
	{
		cout << "~Lazy()" << endl;
	}

private:
	int _a = 0;
	//1.��̬���Աָ��
	static Lazy* _lzObj;
};

Lazy* Lazy::_lzObj = nullptr; //�Ȳ�ʵ��������

//���ܱ��̳е���
//��1) final�ؼ���
class ClassNoInherit final
{
public:

private:
	//��2) ���캯��˽�л�
	ClassNoInherit()
	{

	}
};

//class ClassInherit : public ClassNoInherit
//{
//public:
//	//ClassInherit()
//	//{
//
//	//}
//};