#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//栈上的类
class ClassStack
{
public:
	static ClassStack getObjectStack()
	{
		ClassStack newObj;
		return newObj;
	}

	//new == operator new + copyConstructor/constructor
	//禁止调用new, 为ClassStack定制专属operator new
	void* operator new(size_t size) = delete;

private:
	//构造函数私有化
	ClassStack()
	{
		cout << "ClassStack()" << endl;
	}
};

//堆上的类
class ClassHeap
{
public:
	ClassHeap()
	{
		cout << "ClassHeap" << endl;
	}

	//资源释放接口
	void Destroy()
	{
		delete this;
	}

private:
	//析构函数私有化
	~ClassHeap()
	{
		cout << "~ClassHeap()" << endl;
	}
};

//堆上的类_2
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
	//构造函数私有化
	ClassHeap2()
	{
		cout << "ClassHeap2()" << endl;
	}
};

//不能被拷贝的类
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

////单例模式
//饿汉模式
//在main函数之前就进行构造
class Hungry
{
public:
	//3.获取对象实例
	static Hungry& getInstance()
	{
		return _huObj;
	}

	//4.提供操作接口
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

	//5.禁用拷贝
	Hungry(const Hungry& huObj) = delete;
	Hungry& operator=(const Hungry& huObj) = delete;

private:
	//2.构造函数私有
	Hungry(int a)
	{
		cout << "Hungry()" << endl;
	}

private:
	//1.静态类成员
	static Hungry _huObj;
	int _a;
};

Hungry Hungry::_huObj(0); //直接实例化出一个对象

//懒汉模式
//第一次使用的时候才构造对象
class Lazy
{
public:
	//获取对象接口
	static Lazy& getLzObj()
	{
		if (_lzObj == nullptr) {
			_lzObj = new Lazy;
		}
		return *_lzObj;
	}

	//3.提供操作接口
	void set(int a)
	{
		_a = a;
	}

	int get()
	{
		return _a;
	}

	//4.提供主动释放接口
	//可以 中途显示释放 或者
	//做一些特殊动作(持久化等)
	void Destroy()
	{
		//调用析构，可以进行一些特殊动作
		delete this;
	}

	//5.禁用拷贝
	Lazy(const Lazy& lz) = delete;
	Lazy& operator=(const Lazy& lz) = delete;

private:
	//2.构造和析构私有化
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
	//1.静态类成员指针
	static Lazy* _lzObj;
};

Lazy* Lazy::_lzObj = nullptr; //先不实例化对象

//不能被继承的类
//法1) final关键字
class ClassNoInherit final
{
public:

private:
	//法2) 构造函数私有化
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