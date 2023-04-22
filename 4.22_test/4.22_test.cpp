#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;

class Stack
{
	typedef int StackDataType;
private:
	StackDataType* a_;
	int top_;
	int capacity_;
	
public:
	Stack(int capacity = 10)
	{
		a_ = (StackDataType*)malloc(sizeof(StackDataType) * capacity);
		assert(a_);
		top_ = 0;
		capacity_ = capacity;
	}

	void Push(StackDataType x)
	{
		if (capacity_ == top_)
		{
			StackDataType* tmp = (StackDataType*)realloc(a_, 
				sizeof(StackDataType) * 2 * capacity_);
			if (tmp == nullptr) {
				return;
			}
			a_ = tmp;
			capacity_ *= 2;
		}
		a_[top_++] = x;
	}

	bool isEmpty()
	{
		return top_ == 0;
	}

	void Pop()
	{
		assert(!isEmpty());
		top_--;
	}

	StackDataType Top()
	{
		assert(!isEmpty());
		return a_[top_ - 1];
	}
};

int main()
{
	Stack sT;
	sT.Push(1);
	sT.Push(2);
	sT.Push(3);
	sT.Push(4);

	while (!sT.isEmpty())
	{
		cout << sT.Top() << ' ';
		sT.Pop();
	}
	return 0;
}