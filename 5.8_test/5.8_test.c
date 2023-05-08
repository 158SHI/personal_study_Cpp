#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void toBin(unsigned int num, char* str, int* pi)
{
	char index[] = "0123456789abcdef";
	if (num >= 16)
	{
		toBin(num / 16, str, pi);
	}
	str[(*pi)++] = index[num % 16];
}

int main()
{
	char* str = (char*)calloc(100, sizeof(char));
	assert(str);
	int i = 0;
	toBin(-1, str, &i);
	//_itoa(26, str, 16);
	printf(str);
	return 0;
}