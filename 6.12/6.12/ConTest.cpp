#define _CRT_SECURE_NO_WARNINGS 1

#include "Contact.h"

//void test1()
//{
//	Contact Con;
//	Con.Push();
//	Con.Push();
//	Con.Push();
//	Con.Show();
//}
//
//void test2()
//{
//	Contact Con;
//	Con.Push();
//	Con.Push();
//	Con.Show();
//	Con.Erase();
//	Con.Show();
//}
//
//void test3()
//{
//	Contact Con1;
//	Contact Con2;
//	Con1.Push();
//	Con2.Push();
//	Con1 = Con2;
//	Con1.Show();
//}
//
//void test4()
//{
//	Contact Con;
//	Con.Push();
//	Con.Push();
//	Con.Show();
//	Con.Modify();
//	Con.Show();
//}

//
//void test5()
//{
//	Sys s;
//	s.Add();
//	s.Add();
//	s.Show();
//	s.Delete();
//	s.Show();
//}

void test()
{
	Sys sys;
	sys.Load();
	int option;
	do
	{
		menu();
		cout << "ÇëÑ¡Ôñ:";
		cin >> option;
		switch (option)
		{
		case NEW_CONTACT:
			sys.Add();
			break;
		case DELE_CONTACT:
			sys.Delete();
			break;
		case SHOW_CONTACT:
			sys.Show();
			break;
		case ENTER_CONTACT:
			sys.Enter();
			break;
		case EXIT:
			sys.Save();
			break;
		default:
			cout << "ÊäÈëÓÐÎó_" << endl;
			break;
		}
	} while (option);
}

int main()
{
	test();
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	return 0;
}