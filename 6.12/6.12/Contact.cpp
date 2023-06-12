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
	cout << "����¼�¼��" << endl;
	cin >> newInfo;
	_info.push_back(newInfo); //ֱ�ӵ�������Ľӿ�
	system("cls"); //Windows�������ӿڣ���ҪΪ�˲���ʱ�������ۣ���Ӱ���߼�ʵ��
	cout << "��ӳɹ�_" << endl;
}

list<info>::iterator Contact::Search(void)
{
	string name;
	cout << "������Ҫ����/ɾ��/�޸��˵�������";
	cin >> name;
	auto it = _info.begin();
	for (; it != _info.end(); ++it)
	{
		if ((*it).name == name) {
			return it; //�ҵ��ˣ�����Ŀ��ڵ�ĵ�����
		}
	}
	cout << "δ�ҵ������Ϣ_" << endl;
	return it;
}

void Contact::Erase(void)
{
	auto pos = Search(); //�ȵ��ò��Һ����ҵ�Ŀ��ڵ�
	//�ҵ��ˣ�ִ��ɾ��
	if (pos != _info.end())
	{
		_info.erase(pos);
		system("cls");
		cout << "ɾ����¼�ɹ�_" << endl;
	}
}

void Contact::Modify(void)
{
	auto pos = Search();
	cout << "����������Ϣ��" << endl;
	cin >> *pos;
	system("cls");
	cout << "�޸ĳɹ�_" << endl;
}

void Contact::Show(void)
{
	system("cls");
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "Name", "Age", "Sex", "Address", "PhoneNum");
	//���������ӡ��Ϣ
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
		file << "# "; //���ڶ�ȡ���ݷ��㣬��ͨѶ��Ϣ��'#'��ʶ
		//������������ļ�
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
	cout << "�½�ͨѶ¼����:";
	cin >> ConName;
	//�����ͬ���Ƶ�ͨѶ¼�Ƿ����
	for (auto& con : _SysData)
	{
		if (con._ConName == ConName) {
			system("cls");
			cout << "��ͨѶ¼�Ѵ���_" << endl;
			return;
		}
	}
	Contact newCon(ConName);
	_SysData.push_back(newCon);
	system("cls");
	cout << "�½��ɹ�_" << endl;
}

void Sys::Delete(void)
{
	string name;
	cout << "������Ҫɾ����ͨѶ¼���ƣ�";
	cin >> name;
	auto it = _SysData.begin();
	for (; it != _SysData.end(); ++it)
	{
		//�ҵ�ָ���ڵ㣬ִ��ɾ��
		if (it->_ConName == name)
		{
			_SysData.erase(it);
			system("cls");
			cout << "ɾ���ɹ�_" << endl;
			return;
		}
	}
	system("cls");
	cout << "δ�ҵ������Ϣ_" << endl;
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
	cout << "������Ҫ�����ͨѶ¼���ƣ�";
	cin >> name;
	auto it = _SysData.begin();
	for (; it != _SysData.end(); ++it)
	{
		//�ҵ�Ŀ��ͨѶ¼������
		if (it->_ConName == name)
		{
			system("cls");
			cout << "����ɹ�_" << endl;
			cout << "Contact Name:" << it->_ConName << endl;
			break;
		}
	}
	if (it == _SysData.end()) {
		cout << "δ�ҵ������Ϣ_" << endl;
		return;
	}

	int optionCon;
	//����ͨѶ¼�����ѡ��
	do
	{
		menuForContact();
		cout << "��ѡ��:";
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
			cout << "��������_" << endl;
			break;
		}
	} while (optionCon);
}

void Sys::Save(void)
{
	//�����ݷֲ��д�뵽�ļ���
	ofstream file(fileName);
	for (auto& con : _SysData) {
		file << "$ "; //������ͬ��ͨѶ¼������'$'��ʶ
		file << con;
	}
	file.close();
}

void Sys::Load(void)
{
	ifstream file(fileName);
	//tmp��������Ϊ���жϸ��е���Ϣ����
	char tmp = '@'; //��ʼ��������tmp�����ֵ
	while (file && file.peek() != EOF)
	{
		if (tmp != '$') {
			file >> tmp;
		}

		string name;
		file >> name; //��ͨѶ¼����
		Contact newCon(name);
		//��ͨѶ¼�ڲ���Ϣ
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
	cout << "+----ͨѶ¼����ϵͳ----+" << endl;
	cout << "+----1.������ͨѶ¼----+" << endl;
	cout << "+-----2.ɾ��ͨѶ¼-----+" << endl;
	cout << "+-----3.�鿴ͨѶ¼-----+" << endl;
	cout << "+-----4.����ͨѶ¼-----+" << endl;
	cout << "+------0.�˳�ϵͳ------+" << endl;
}

void menuForContact(void)
{
	cout << "+-----1.��Ӽ�¼-----+" << endl;
	cout << "+-----2.���Ҽ�¼-----+" << endl;
	cout << "+-----3.ɾ����¼-----+" << endl;
	cout << "+-----4.�޸ļ�¼-----+" << endl;
	cout << "+-----5.չʾ��¼-----+" << endl;
	cout << "+----0.�˳�ͨѶ¼----+" << endl;
}

