#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ������ת��Ϊʮ����
int binaryToDecimal(long long binary)
{
    int decimal = 0;
    int base = 1;

    while (binary > 0)
    {
        int lastDigit = binary % 10; // ��ȡ�������������һλ����
        binary = binary / 10; // ȥ�����һλ����
        decimal += lastDigit * base; // ������������ת��Ϊʮ���Ʋ��ӵ������
        base *= 2; // ���½��ƻ���
    }

    return decimal; // ����ת�����ʮ������
}

// �˽���ת��Ϊʮ����
int octalToDecimal(long long octal)
{
    int decimal = 0;
    int base = 1;

    while (octal > 0)
    {
        int lastDigit = octal % 10; // ��ȡ�˽����������һλ����
        octal = octal / 10; // ȥ�����һλ����
        decimal += lastDigit * base; // ���˽�������ת��Ϊʮ���Ʋ��ӵ������
        base *= 8; // ���½��ƻ���
    }

    return decimal; // ����ת�����ʮ������
}

// ʮ������ת��Ϊʮ����
int hexadecimalToDecimal(char hexadecimal[])
{
    int decimal = 0;
    int length = 0;

    while (hexadecimal[length] != '\0')
    {
        length++; // ����ʮ�������ַ����ĳ���
    }

    int base = 1;

    for (int i = length - 1; i >= 0; i--)
    {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
        {
            decimal += (hexadecimal[i] - '0') * base; // ��ʮ���������֣�0-9��ת��Ϊʮ���Ʋ��ӵ������
        }
        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F')
        {
            decimal += (hexadecimal[i] - 'A' + 10) * base; // ��ʮ��������ĸ��A-F��ת��Ϊʮ���Ʋ��ӵ������
        }

        base *= 16; // ���½��ƻ���
    }

    return decimal; // ����ת�����ʮ������
}

// ʮ����ת��Ϊ������
long long decimalToBinary(int decimal)
{
    long long binary = 0;
    int remainder;
    int i = 1;

    while (decimal > 0)
    {
        remainder = decimal % 2; // ��ȡʮ����������2���������������Ƶ����һλ����
        decimal = decimal / 2; // ����ʮ��������ȥ�����һλ����
        binary += remainder * i; // ���������Ի������ӵ������
        i *= 10; // ���»���
    }

    return binary; // ����ת����Ķ�������
}

// ʮ����ת��Ϊ�˽���
long long decimalToOctal(int decimal)
{
    long long octal = 0;
    int remainder;
    int i = 1;

    while (decimal > 0)
    {
        remainder = decimal % 8; // ��ȡʮ����������8�����������˽��Ƶ����һλ����
        decimal = decimal / 8; // ����ʮ��������ȥ�����һλ����
        octal += remainder * i; // ���������Ի������ӵ������
        i *= 10; // ���»���
    }

    return octal; // ����ת����İ˽�����
}

// ʮ����ת��Ϊʮ������
void decimalToHexadecimal(int decimal)
{
    char hexadecimal[100];
    int i = 0;

    while (decimal > 0)
    {
        int remainder = decimal % 16; // ��ȡʮ����������16����������ʮ�����Ƶ�һλ����

        if (remainder < 10)
        {
            hexadecimal[i] = remainder + '0'; // ���������0-9����ת��Ϊ��Ӧ���ַ�
        }
        else
        {
            hexadecimal[i] = remainder + 'A' - 10; // ���������10-15����ת��Ϊ��Ӧ����ĸ��A-F��
        }

        decimal = decimal / 16; // ����ʮ��������ȥ�����һλ����
        i++; // ��������
    }

    printf("ʮ�����Ʊ�ʾ: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hexadecimal[j]); // �������ת�����ʮ��������
    }
    printf("\n");
}

int main()
{
    int number;
    int base;

    printf("����������ֵĽ��� (2, 8, 10, 16): ");
    scanf("%d", &base);

    if (base == 2)
    {
        printf("������һ������: ");
        scanf("%d", &number);
        long long binary = decimalToBinary(number);
        printf("�����Ʊ�ʾ: %lld\n", binary);

        decimalToOctal(binary);
        decimalToHexadecimal(binary);
    }
    else if (base == 8)
    {
        printf("������һ������: ");
        scanf("%d", &number);
        long long octal = decimalToOctal(number);
        printf("�˽��Ʊ�ʾ: %lld\n", octal);

        int decimal = octalToDecimal(octal);
        decimalToBinary(decimal);
        decimalToHexadecimal(decimal);
    }
    else if (base == 10)
    {
        printf("������һ������: ");
        scanf("%d", &number);
        printf("ʮ���Ʊ�ʾ: %d\n", number);

        long long binary = decimalToBinary(number);
        printf("�����Ʊ�ʾ: %lld\n", binary);

        long long octal = decimalToOctal(number);
        printf("�˽��Ʊ�ʾ: %lld\n", octal);

        decimalToHexadecimal(number);
    }
    else if (base == 16)
    {
        char hexadecimal[100];
        printf("ʮ�����Ʊ�ʾ: ");
        scanf("%s", hexadecimal);

        int decimal = hexadecimalToDecimal(hexadecimal);
        printf("ʮ���Ʊ�ʾ: %d\n", decimal);

        long long binary = decimalToBinary(decimal);
        printf("�����Ʊ�ʾ: %lld\n", binary);

        long long octal = decimalToOctal(decimal);
        printf("�˽��Ʊ�ʾ: %lld\n", octal);
    }
    else
    {
        printf("��Ч�Ľ���ѡ��\n");
        return 1;
    }

    return 0;
}