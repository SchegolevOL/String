/*Написать функции:
1. Проверяет, является ли строка палиндромом (ого, или, 12321)
2. Проверяет, является ли строка целым десятичным числом
3. Если строка - десятичное число, то функция возвращает его int-овое значение.
4. Проверяет, является ли строка двоичным числом
5. Если строка - двоичное число, то функция возвращает его десятичное значение.
6. Проверяет, является ли строка шестнадцатеричным числом
7. Если строка - шестнадцатеричное число, то функция возвращает его десятичное значение.
*/
#include <iostream>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

size_t Strlen(const char* string)
{
	size_t str = 0;
	while (*string)
	{
		str++;
		string++;
	}
	return  str;
}

bool PalindromeStr(const char* str)//Проверяет, является ли строка палиндромом
{
	size_t length = Strlen(str);
	for (size_t i = 0; i < length / 2; i++)
		if (*(str + i) != *(str - i + length - 1))
			return 0;
	return 1;
}

bool DecNumStr(const char* str)
{
	size_t length = Strlen(str);
	for (size_t i = 0; i < length; i++)
		if (*(str + i) < 48 || *(str + i) > 57)
			return 0;
	return 1;
}

int IntDecStr(const char* str)
{
	int number = 0;
	int n = 1;
	size_t length = Strlen(str);
	for (size_t i = 0; i < length; i++)
	{
		number += (*(str - i + length - 1) - 48) * n;
		n *= 10;
	}
	return number;
}

bool BinNumStr(const char* str)
{
	size_t length = Strlen(str);
	for (size_t i = 0; i < length; i++)
		if (*(str + i) < 48 || *(str + i) > 49)
			return 0;
	return 1;
}

long long degree(const int a, const int b)
{
	return b < 1 ? 1 : degree(a, b - 1) * a;
}

int IntDecBinStr(const char* str)
{
	int number = 0;
	size_t length = Strlen(str);
	for (size_t i = 0; i < length; i++)
		number += (*(str - i + length - 1) - 48.0) * degree(2, i);
	return number;
}

bool HexNumStr(const char* str)
{
	size_t length = Strlen(str);
	for (size_t i = 0; i < length; i++)
		if (*(str + i) < 48 || *(str + i) > 57 && *(str + i) < 65 || *(str + i) > 70)
			return 0;
	return 1;
}

int IntDecHexStr(const char* str)
{
	int number = 0;
	size_t length = Strlen(str);
	for (size_t i = 0; i < length; i++)
	{
		if (*(str + i) >= 48 && *(str + i) <= 57)
		{
			number += (*(str - i + length - 1) - 48.0) * degree(16, i);
		}
		if (*(str + i) >= 65 && *(str + i) <= 70)
		{
			number += (*(str - i + length - 1) - 55.0) * degree(16, i);
		}

	}
	return number;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* str = new char[255];
	cout << "Введите строку: ";
	cin.getline(str, 255);
	PalindromeStr(str) == 0 ? cout << "Не полиндром" : cout << "Полиндром";
	cout << endl;
	DecNumStr(str) == 0 ? cout << "Число не десятичное" : cout << IntDecStr(str);
	cout << endl;
	BinNumStr(str) == 0 ? cout << "Число не двоичное " : cout << "Десятичный вид " << IntDecBinStr(str);
	cout << endl;
	HexNumStr(str) == 0 ? cout << "Число не шестнадцатичичное " : cout << "Десятичный вид " << IntDecHexStr(str);
	cout << endl;

	delete[]str;
	return 0;
}