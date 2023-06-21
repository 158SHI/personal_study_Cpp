#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 二进制转换为十进制
int binaryToDecimal(long long binary)
{
    int decimal = 0;
    int base = 1;

    while (binary > 0)
    {
        int lastDigit = binary % 10; // 获取二进制数的最后一位数字
        binary = binary / 10; // 去掉最后一位数字
        decimal += lastDigit * base; // 将二进制数字转换为十进制并加到结果中
        base *= 2; // 更新进制基数
    }

    return decimal; // 返回转换后的十进制数
}

// 八进制转换为十进制
int octalToDecimal(long long octal)
{
    int decimal = 0;
    int base = 1;

    while (octal > 0)
    {
        int lastDigit = octal % 10; // 获取八进制数的最后一位数字
        octal = octal / 10; // 去掉最后一位数字
        decimal += lastDigit * base; // 将八进制数字转换为十进制并加到结果中
        base *= 8; // 更新进制基数
    }

    return decimal; // 返回转换后的十进制数
}

// 十六进制转换为十进制
int hexadecimalToDecimal(char hexadecimal[])
{
    int decimal = 0;
    int length = 0;

    while (hexadecimal[length] != '\0')
    {
        length++; // 计算十六进制字符串的长度
    }

    int base = 1;

    for (int i = length - 1; i >= 0; i--)
    {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
        {
            decimal += (hexadecimal[i] - '0') * base; // 将十六进制数字（0-9）转换为十进制并加到结果中
        }
        else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F')
        {
            decimal += (hexadecimal[i] - 'A' + 10) * base; // 将十六进制字母（A-F）转换为十进制并加到结果中
        }

        base *= 16; // 更新进制基数
    }

    return decimal; // 返回转换后的十进制数
}

// 十进制转换为二进制
long long decimalToBinary(int decimal)
{
    long long binary = 0;
    int remainder;
    int i = 1;

    while (decimal > 0)
    {
        remainder = decimal % 2; // 获取十进制数除以2的余数，即二进制的最后一位数字
        decimal = decimal / 2; // 更新十进制数，去掉最后一位数字
        binary += remainder * i; // 将余数乘以基数并加到结果中
        i *= 10; // 更新基数
    }

    return binary; // 返回转换后的二进制数
}

// 十进制转换为八进制
long long decimalToOctal(int decimal)
{
    long long octal = 0;
    int remainder;
    int i = 1;

    while (decimal > 0)
    {
        remainder = decimal % 8; // 获取十进制数除以8的余数，即八进制的最后一位数字
        decimal = decimal / 8; // 更新十进制数，去掉最后一位数字
        octal += remainder * i; // 将余数乘以基数并加到结果中
        i *= 10; // 更新基数
    }

    return octal; // 返回转换后的八进制数
}

// 十进制转换为十六进制
void decimalToHexadecimal(int decimal)
{
    char hexadecimal[100];
    int i = 0;

    while (decimal > 0)
    {
        int remainder = decimal % 16; // 获取十进制数除以16的余数，即十六进制的一位数字

        if (remainder < 10)
        {
            hexadecimal[i] = remainder + '0'; // 如果余数是0-9，则转换为相应的字符
        }
        else
        {
            hexadecimal[i] = remainder + 'A' - 10; // 如果余数是10-15，则转换为相应的字母（A-F）
        }

        decimal = decimal / 16; // 更新十进制数，去掉最后一位数字
        i++; // 更新索引
    }

    printf("十六进制表示: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hexadecimal[j]); // 逆序输出转换后的十六进制数
    }
    printf("\n");
}

int main()
{
    int number;
    int base;

    printf("请输入该数字的进制 (2, 8, 10, 16): ");
    scanf("%d", &base);

    if (base == 2)
    {
        printf("请输入一个数字: ");
        scanf("%d", &number);
        long long binary = decimalToBinary(number);
        printf("二进制表示: %lld\n", binary);

        decimalToOctal(binary);
        decimalToHexadecimal(binary);
    }
    else if (base == 8)
    {
        printf("请输入一个数字: ");
        scanf("%d", &number);
        long long octal = decimalToOctal(number);
        printf("八进制表示: %lld\n", octal);

        int decimal = octalToDecimal(octal);
        decimalToBinary(decimal);
        decimalToHexadecimal(decimal);
    }
    else if (base == 10)
    {
        printf("请输入一个数字: ");
        scanf("%d", &number);
        printf("十进制表示: %d\n", number);

        long long binary = decimalToBinary(number);
        printf("二进制表示: %lld\n", binary);

        long long octal = decimalToOctal(number);
        printf("八进制表示: %lld\n", octal);

        decimalToHexadecimal(number);
    }
    else if (base == 16)
    {
        char hexadecimal[100];
        printf("十六进制表示: ");
        scanf("%s", hexadecimal);

        int decimal = hexadecimalToDecimal(hexadecimal);
        printf("十进制表示: %d\n", decimal);

        long long binary = decimalToBinary(decimal);
        printf("二进制表示: %lld\n", binary);

        long long octal = decimalToOctal(decimal);
        printf("八进制表示: %lld\n", octal);
    }
    else
    {
        printf("无效的进制选择！\n");
        return 1;
    }

    return 0;
}