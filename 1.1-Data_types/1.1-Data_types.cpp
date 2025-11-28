// 1.1-Data_types.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int main()
{
    // Изучите внутреннее устройство и характеристики базовых типов данных:

    // 1. целочисленные типы (знаковые и беззнаковые, разного размера)
    // Размеры
    cout << "int size (byte): " << sizeof(int) << endl;
    cout << "long size: " << sizeof(long) << endl;
    cout << "long long size: " << sizeof(long long) << endl;
    cout << endl;
    // Знаковые
    cout << "int min: " << INT_MIN << endl;
    cout << "int max: " << INT_MAX << endl;
    cout << "long min: " << LONG_MIN << endl;
    cout << "long max: " << LONG_MAX << endl;
    cout << "long long min: " << LLONG_MIN << endl;
    cout << "long long max: " << LLONG_MAX << endl;
    cout << endl;
    int a = 2147483647;
    printf("Positive int overflow: %d + 1 = %d\n", a, a + 1);
    a = -2147483648;
    printf("Negative int overflow: %d - 1 = %d\n", a, a - 1);
    cout << endl;
    // Беззнаковые
    cout << "unsigned int max: " << UINT_MAX << endl;
    cout << "unsigned long max: " << ULONG_MAX << endl;
    cout << "unsigned long long max: " << ULLONG_MAX << endl;
    cout << endl;
    unsigned int b = 4294967295;
    printf("Positive unsigned int overflow: %u + 1 = %u\n", b, b + 1);
    b = 0;
    printf("Negative unsigned int overflow: %u - 1 = %u\n", b, b - 1);
    cout << endl;

    // 2. вещественные типы (разной точности)
    cout << "float size: " << sizeof(float) << endl;
    cout << "double size: " << sizeof(double) << endl;
    cout << "long double size: " << sizeof(long double) << endl;
    cout << "float range: -3.4E+38 - 3.4E+38" << endl;
    cout << "double range: -1.7E+308 - 1.7E+308" << endl;
    cout << endl;

    // 3. булев тип
    cout << "bool size: " << sizeof(bool) << endl;
    cout << endl;

    // 4. символы и строки (char и unsigned char, для строк достаточно std::string)
    // char
    cout << "char size (bit): " << CHAR_BIT << endl;
    cout << "char size (byte): " << sizeof(char) << endl;
    cout << "wchar_t size: " << sizeof(wchar_t) << endl;
    cout << "char16_t size: " << sizeof(char16_t) << endl;
    cout << "char32_t size: " << sizeof(char32_t) << endl;
    cout << endl;
    cout << "char min: " << CHAR_MIN << endl;
    cout << "char max: " << CHAR_MAX << endl;
    cout << "unsigned char max: " << UCHAR_MAX << endl;
    cout << "wchar min: " << WCHAR_MIN << endl;
    cout << "wchar max: " << WCHAR_MAX << endl;
    cout << endl;
    // string
    cout << "string size: " << sizeof(string) << endl;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    cout << "s lenght: " << s.length() << endl;
    cout << "s size: " << sizeof(s) << endl;
    s.append("aa");
    cout << "s lenght: " << s.length() << endl;
    cout << "s size: " << sizeof(s) << endl;
    s.append("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa  aaaaaaaaaaaaa bbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
    cout << "s lenght: " << s.length() << endl;
    cout << "s size: " << sizeof(s) << endl;

    // Узнайте размеры и диапазоны типов, внутреннее представление (сравните с документацией), исследуйте, что происходит при переполнении, на границах, есть ли зависимость представления от размера (для строк).

    // Используйте встроенные возможности языка, в том числе стандартную библиотеку и указатели.
}
