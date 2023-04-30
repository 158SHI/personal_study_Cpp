#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int key = a[i];
		while (end >= 0)
		{
			if (key < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = key;
	}
}

int GetMidI(int* a, int left, int right)
{
	int midI = (left + right) / 2;

	if (a[left] < a[midI])
	{
		if (a[midI] < a[right]) {
			return midI;
		}
		else if (a[midI < a[left]]) {
			return left;
		}
		else {
			return right;
		}
	}
	else //a[left] >= a[mid]
	{
		if (a[midI] > a[right]) {
			return midI;
		}
		else if (a[midI] > a[left]) {
			return left;
		}
		else {
			return right;
		}
	}
}

//Hoare
int PartSort1(int* a, int left, int right)
{
	int keyi = GetMidI(a, left, right);
	Swap(a + left, a + keyi);

	int key = a[left];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && a[end] >= key) {
			end--;
		}
		while (begin < end && a[begin] <= key) {
			begin++;
		}
		Swap(a + begin, a + end);
	}
	Swap(a + begin, a + left);
	
	keyi = begin;
	return keyi;
}

int PartSort2(int* a, int left, int right)
{
	int midI = GetMidI(a, left, right);
	Swap(a + left, a + midI);

	int pit = left;
	int key = a[left];

	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && a[end] >= key) {
			end--;
		}
		a[pit] = a[end];
		pit = end;
		while (begin < end && a[begin] <= key) {
			begin++;
		}
		a[pit] = a[begin];
		pit = begin;
	}
	a[pit] = key;
	
	return begin;
}

int PartSort3(int* a, int left, int right)
{
	Swap(a + left, a + GetMidI(a, left, right));

	int keyi = left;
	int cur = left;
	int prev = left;

	while (cur <= right)
	{
		if (a[cur] >= a[keyi]) {
			cur++;
		}
		else
		{
			prev++;
			Swap(a + prev, a + cur);
			cur++;
		}
	}
	Swap(a + prev, a + keyi);

	keyi = prev;
	return keyi;
}

//快排三路划分
void QuickSort(int* a, int left, int right)
{
	if (left >= right) {
		return;
	}

	if ((right - left + 1) > 10)
	{
		int keyi = GetMidI(a, left, right);
		Swap(a + left, a + keyi);

		int key = a[left];
		int begin = left;
		int end = right;
		int cur = left;

		while (cur <= end)
		{
			if (a[cur] < key)
			{
				Swap(a + cur, a + begin);
				cur++;
				begin++;
			}
			else if (a[cur] > key)
			{
				Swap(a + cur, a + end);
				end--;
			}
			else {
				cur++;
			}
		}

		//[left, begin - 1] [begin, end] [end + 1, right]
		QuickSort(a, left, begin - 1);
		QuickSort(a, end + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}

void SortTest(void)
{
	//int arr[] = { 6,1,2,7,9,3,4 };
	int arr[] = { 2,2,2,2,2,2,2,2,0 };
	//int arr[] = { 6,3,4,7,1,6,0,3,6,2,6 };
	//int arr[] = { 59, 74, 94, 12, 78 ,86,
	//	98, 48, 45, 82, 66, 34, 58, 55,
	//	90, 93 ,77 ,29, 73, 28 ,2 ,16 ,63,
	//	87 ,54 ,31 ,52 ,13, 27 ,30 ,56 ,9 ,
	//	51 ,7 ,64, 39, 17, 100 ,96 ,99 ,18 ,46,
	//	24 ,75, 47, 20, 83, 4, 95 ,91 };
	//int arr[] = { 0,42590,16666,2,25003,42592,4,
	//	41669,49266,6,25005,16670,8,33336,46706,10,
	//	25007,44447,12,38890,16674,14,25009,27782,16
	//	,41671,38892,18,25011,16678,20,33340,46299,22,
	//	25013,42594,24,47530,16682,26,25015,35190,28,
	//	41673,44449,30,25017,16686,32,33344,27790,34,
	//	25019,38896,36,45062,16690,38,25021,48534,40,41675
	//	,47532,42,25023,16694,44,33348,49268,46,25025,44451,
	//	48,38898,16698,50,25027,27798,52,41677,38900,54,25029,
	//	16702,56,33352,42600,58,25031,49179,60,46300 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, sz - 1);
	
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
}

int main()
{
	SortTest();
	return 0;
}