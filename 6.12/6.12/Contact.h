#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
#include <string>
#include <assert.h>
#include <fstream>
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::list;
using std::ofstream;
using std::ifstream;

//info结构体用来存储各条通讯信息
struct info
{
	//设计>>重载，方便数据输入
	friend istream& operator>>(istream& cin, info& i);

	string name;
	string sex;
	size_t age = 0;
	string address;
	string num;
};

//用链表存储通讯录，设计Contact类对其进行封装
class Contact
{
	friend class Sys; //将Sys设计为Contact的友元类，便于Sys访问通讯录名称和信息
	//设计<<重载，方便将数据写入到文件
	friend ofstream& operator<<(ofstream& file, Contact& con);
private:
	//通讯录名称
	string _ConName;
	//单条通讯录记录的信息
	list<info> _info;

public:
	Contact(string ConName = " ")
		:_ConName(ConName)
	{ }

	//添加通讯录信息
	//这里将参数列表设置为void，方便在函数体内提醒用户进行信息输入，下文同理
	void Push(void);
	//查找通讯录信息，支持姓名查找
	list<info>::iterator Search(void);
	//删除信息
	void Erase(void);
	//修改信息
	void Modify(void);
	//展示信息
	void Show(void);
};

//Sys类用来整合通讯录
class Sys
{
private:
	list<Contact> _SysData; //用链表存储通讯录

public:
	static const char* fileName;

	void Add(void); //新建通讯录
	void Delete(void); //删除通讯录
	void Show(void); //展示所有通讯录
	void Enter(void); //进入通讯录
	void Save(void);  //保存数据至文件
	void Load(void);  //加载数据至内存
};

//整体的选项枚举
enum options
{
	EXIT,
	NEW_CONTACT,
	DELE_CONTACT,
	SHOW_CONTACT,
	ENTER_CONTACT
};

//通讯录的选项枚举
enum optionsForContact
{
	EXIT_CON,
	ADD,
	SEARCH,
	ERASE,
	MODIFY,
	SHOW
};

//总体菜单
void menu(void);

//通讯录菜单
void menuForContact(void);