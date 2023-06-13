#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

const char* fileName = "random.data";

const int randomCount = 10000;

void RandomCreat()
{
	srand((unsigned int)time(NULL));
	ofstream file(fileName);
	for (int i = 0; i < randomCount; ++i) {
		file << rand() << endl;
	}
	file.close();
}

void InsertSort(int* a, int n)
{

}

void OPtest(void)
{
	ifstream file(fileName);
	int* nums = new int[randomCount];
	int index = 0;
	while (file) {
		file >> nums[index++];
	}
	file.close();

	int begin1 = clock();
	InsertSort(nums, randomCount);
	int end1 = clock();

	int begin2 = clock();
	//ShellSort(nums, randomCount);
	int end2 = clock();

	int begin3 = clock();

	int end3 = clock();

	int begin4 = clock();

	int end4 = clock();

	cout << "InsertSort: " << end1 - begin1 << endl;
	cout << "ShellSort: " << end2 - begin2 << endl;
}