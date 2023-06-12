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

//info�ṹ�������洢����ͨѶ��Ϣ
struct info
{
	//���>>���أ�������������
	friend istream& operator>>(istream& cin, info& i);

	string name;
	string sex;
	size_t age = 0;
	string address;
	string num;
};

//������洢ͨѶ¼�����Contact�������з�װ
class Contact
{
	friend class Sys; //��Sys���ΪContact����Ԫ�࣬����Sys����ͨѶ¼���ƺ���Ϣ
	//���<<���أ����㽫����д�뵽�ļ�
	friend ofstream& operator<<(ofstream& file, Contact& con);
private:
	//ͨѶ¼����
	string _ConName;
	//����ͨѶ¼��¼����Ϣ
	list<info> _info;

public:
	Contact(string ConName = " ")
		:_ConName(ConName)
	{ }

	//���ͨѶ¼��Ϣ
	//���ｫ�����б�����Ϊvoid�������ں������������û�������Ϣ���룬����ͬ��
	void Push(void);
	//����ͨѶ¼��Ϣ��֧����������
	list<info>::iterator Search(void);
	//ɾ����Ϣ
	void Erase(void);
	//�޸���Ϣ
	void Modify(void);
	//չʾ��Ϣ
	void Show(void);
};

//Sys����������ͨѶ¼
class Sys
{
private:
	list<Contact> _SysData; //������洢ͨѶ¼

public:
	static const char* fileName;

	void Add(void); //�½�ͨѶ¼
	void Delete(void); //ɾ��ͨѶ¼
	void Show(void); //չʾ����ͨѶ¼
	void Enter(void); //����ͨѶ¼
	void Save(void);  //�����������ļ�
	void Load(void);  //�����������ڴ�
};

//�����ѡ��ö��
enum options
{
	EXIT,
	NEW_CONTACT,
	DELE_CONTACT,
	SHOW_CONTACT,
	ENTER_CONTACT
};

//ͨѶ¼��ѡ��ö��
enum optionsForContact
{
	EXIT_CON,
	ADD,
	SEARCH,
	ERASE,
	MODIFY,
	SHOW
};

//����˵�
void menu(void);

//ͨѶ¼�˵�
void menuForContact(void);