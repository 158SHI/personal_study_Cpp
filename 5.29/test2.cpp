#include <iostream>
#include <string>

using namespace std;

void test1()
{
  string s1("qwerrt");
  cout << s1.size() << endl;
  s1.assign("123\0\0\0");
  
  cout << s1.size() << endl;
}

int main()
{
  test1();
  return 0;
}
