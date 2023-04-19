#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;

class Stack
{
private:
	int* a_;
	int top_;
	int capacity_;
public:
	void Init(int capacity = 10)
	{
		a_ = (int*)malloc(sizeof(int) * capacity);
		assert(a_);
		top_ = 0;
		capacity_ = capacity;
	}

	void Destroy(void)
	{
		free(a_);
		a_ = nullptr;
		capacity_ = 0;
		top_ = 0;
	}

	void Push(int x)
	{
		a_[top_++] = x;
	}
};

int main()
{
	Stack st;
	st.Init();
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Destroy();
	return 0;
}