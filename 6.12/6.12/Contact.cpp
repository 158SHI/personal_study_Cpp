#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

istream& operator>>(istream& cin, info& i)
{
	cout << "name: ";
	cin >> i.name;
	cout << "sex: ";
	cin >> i.sex;
	cout << "age: ";
	cin >> i.age;
	cout << "address: ";
	cin >> i.address;
	cout << "phonenum: ";
	cin >> i.num;
	return cin;
}

void Contact::Push(void)
{
	info newInfo;
	cout << "添加新记录：" << endl;
	cin >> newInfo;
	_info.push_back(newInfo); //直接调用链表的接口
	system("cls"); //Windows的清屏接口，主要为了操作时清晰美观，不影响逻辑实现
	cout << "添加成功_" << endl;
}

list<info>::iterator Contact::Search(void)
{
	string name;
	cout << "请输入要查找/删除/修改人的姓名：";
	cin >> name;
	auto it = _info.begin();
	for (; it != _info.end(); ++it)
	{
		if ((*it).name == name) {
			return it; //找到了，返回目标节点的迭代器
		}
	}
	cout << "未找到相关信息_" << endl;
	return it;
}

void Contact::Erase(void)
{
	auto pos = Search(); //先调用查找函数找到目标节点
	//找到了，执行删除
	if (pos != _info.end())
	{
		_info.erase(pos);
		system("cls");
		cout << "删除记录成功_" << endl;
	}
}

void Contact::Modify(void)
{
	auto pos = Search();
	cout << "请输入新信息：" << endl;
	cin >> *pos;
	system("cls");
	cout << "修改成功_" << endl;
}

void Contact::Show(void)
{
	system("cls");
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "Name", "Age", "Sex", "Address", "PhoneNum");
	//遍历链表打印信息
	for (auto& e : _info)
	{
		printf("%-20s\t%-4u\t%-5s\t%-20s\t%-12s\n", e.name.c_str(),
			e.age, e.sex.c_str(), e.address.c_str(), e.num.c_str());
	}
}

ofstream& operator<<(ofstream& file, Contact& con)
{
	file << con._ConName << endl;
	for (info message : con._info)
	{
		file << "# "; //便于读取数据方便，将通讯信息用'#'标识
		//将数据输出到文件
		file << message.name << ' ' <<
			message.sex << ' ' <<
			message.age << ' ' <<
			message.address << ' ' <<
			message.num << endl;
	}
	return file;
}

const char* Sys::fileName = "Sys.data";

void Sys::Add(void)
{
	string ConName;
	cout << "新建通讯录名称:";
	cin >> ConName;
	//检查相同名称的通讯录是否存在
	for (auto& con : _SysData)
	{
		if (con._ConName == ConName) {
			system("cls");
			cout << "该通讯录已存在_" << endl;
			return;
		}
	}
	Contact newCon(ConName);
	_SysData.push_back(newCon);
	system("cls");
	cout << "新建成功_" << endl;
}

void Sys::Delete(void)
{
	string name;
	cout << "情输入要删除的通讯录名称：";
	cin >> name;
	auto it = _SysData.begin();
	for (; it != _SysData.end(); ++it)
	{
		//找到指定节点，执行删除
		if (it->_ConName == name)
		{
			_SysData.erase(it);
			system("cls");
			cout << "删除成功_" << endl;
			return;
		}
	}
	system("cls");
	cout << "未找到相关信息_" << endl;
}

void Sys::Show(void)
{
	system("cls");
	printf("%-20s\t%-5s\n", "Contact Name", "Contact Size");
	for (auto& con : _SysData) {
		printf("%-20s\t%-5u\n", con._ConName.c_str(), con._info.size());
	}
}

void Sys::Enter(void)
{
	string name;
	cout << "情输入要进入的通讯录名称：";
	cin >> name;
	auto it = _SysData.begin();
	for (; it != _SysData.end(); ++it)
	{
		//找到目标通讯录，进入
		if (it->_ConName == name)
		{
			system("cls");
			cout << "进入成功_" << endl;
			cout << "Contact Name:" << it->_ConName << endl;
			break;
		}
	}
	if (it == _SysData.end()) {
		cout << "未找到相关信息_" << endl;
		return;
	}

	int optionCon;
	//进入通讯录后的子选项
	do
	{
		menuForContact();
		cout << "请选择:";
		cin >> optionCon;
		switch (optionCon)
		{
		case ADD:
			it->Push();
			break;
		case SEARCH:
			it->Search();
			break;
		case ERASE:
			it->Erase();
			break;
		case MODIFY:
			it->Modify();
			break;
		case SHOW:
			it->Show();
			break;
		case EXIT_CON:
			system("cls");
			break;
		default:
			cout << "输入有误_" << endl;
			break;
		}
	} while (optionCon);
}

void Sys::Save(void)
{
	//将数据分层次写入到文件中
	ofstream file(fileName);
	for (auto& con : _SysData) {
		file << "$ "; //与上文同理，通讯录名称用'$'标识
		file << con;
	}
	file.close();
}

void Sys::Load(void)
{
	ifstream file(fileName);
	//tmp的设置是为了判断各行的信息属性
	char tmp = '@'; //初始化，避免tmp的随机值
	while (file && file.peek() != EOF)
	{
		if (tmp != '$') {
			file >> tmp;
		}

		string name;
		file >> name; //读通讯录名称
		Contact newCon(name);
		//读通讯录内部信息
		while (file)
		{
			file >> tmp;
			if (tmp == '$' || file.peek() == EOF) {
				break;
			}

			info newInfo;
			file >> newInfo.name >> newInfo.sex >> newInfo.age >>
				newInfo.address >> newInfo.num;
			newCon._info.push_back(newInfo);
		}
		_SysData.push_back(newCon);
	}
}

void menu(void)
{
	cout << "+----通讯录管理系统----+" << endl;
	cout << "+----1.建立新通讯录----+" << endl;
	cout << "+-----2.删除通讯录-----+" << endl;
	cout << "+-----3.查看通讯录-----+" << endl;
	cout << "+-----4.进入通讯录-----+" << endl;
	cout << "+------0.退出系统------+" << endl;
}

void menuForContact(void)
{
	cout << "+-----1.添加记录-----+" << endl;
	cout << "+-----2.查找记录-----+" << endl;
	cout << "+-----3.删除记录-----+" << endl;
	cout << "+-----4.修改记录-----+" << endl;
	cout << "+-----5.展示记录-----+" << endl;
	cout << "+----0.退出通讯录----+" << endl;
}

