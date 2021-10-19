#include <iostream>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
/*bool is_mac_address(char str[]);//Проверяет, является ли строка MAC-адресом
  bool is_ip_address(char str[]);//Проверяет, является ли строка IP-адресом*/

void UpReg(char* string)
{
	while (*string)
	{
		if (*string >= 'a' && *string <= 'z' || *string >= 'а' && *string <= 'я')
		{
			*string -= 32;
		}
		string++;
	}
}

bool is_mac_address(const char* string)
{

	size_t length = strlen(string);
	if (length != 15 && length != 17) return 0;
	char* str = new char[255];
	for (size_t i = 0; i < length + 1; i++)
	{
		*(str + i) = *(string + i);
	}

	UpReg(str);
	if (length == 17)
	{
		for (size_t i = 0; i < length; i = i + 3)
			for (size_t j = i; j < 2; j++)
				if (*(str + i + j) < '0' || *(str + i + j) > '9' && *(str + i + j) < 'A' || *(str + i + j) > 'F')
				{
					delete[] str;
					return 0;
				}
		for (size_t i = 2; i < length - 2; i = i + 3)
			if (*(str + i) != '-' && *(str + i) != ':')
			{
				delete[] str;
				return 0;
			}
	}
	else
	{
		for (size_t i = 0; i < length; i = i + 4)
			for (size_t j = i; j < 3; j++)
				if (*(str + i + j) < '0' || *(str + i + j) > '9' && *(str + i + j) < 'A' || *(str + i + j) > 'F')
				{
					delete[] str;
					return 0;
				}
		for (size_t i = 3; i < length - 3; i = i + 4)
			if (*(str + i) != '.')
			{
				delete[] str;
				return 0;
			}
	}
	delete[] str;
	return 1;
}



bool is_ip_address(const char* string)
{
	size_t i = 0;
	char* pCh;//Указатель на '.'
	int n;//длина цифр
	int c = 0;//счетчик наборов цифр


	size_t length = strlen(string);
	char* str = new char[255];
	for (size_t i = 0; i < length + 1; i++)
	{
		*(str + i) = *(string + i);
	}
	str[length] = '.';
	str[length + 1] = '\0';
	for (size_t i = 0; i < length + 1; i++)
	{
		if ((*(str + i) < '0' || *(str + i) > '9') && *(str + i) != '.')
		{
			delete[]str;
			return 0;
		}

	}
	for (size_t i = 0; i < length; i++)
	{
		pCh = strchr(str, '.');
		n = pCh - str;
		if (n > 3 || n < 1)
		{
			delete[]str;
			return 0;
		}
		int d = 0;
		int nD = 1;
		for (size_t j = 0; j < n; j++)
		{
			d += (*(str - j + n - 1) - 48) * nD;
			nD *= 10;
		}
		if (d > 255)
		{
			delete[]str;
			return 0;
		}
		for (size_t j = 0; j < length; j++)
		{
			str[j] = str[j + n + 1];
		}
		length = length - n;
		c = c++;
	}
	if (c == 4)
	{
		delete[]str;
		return 1;
	}
	else
	{
		delete[]str;
		return 0;
	}
}







int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char* str = new char[255];
	cout << "Введите МАС адресс: ";
	cin.getline(str, 255);


	if (is_mac_address(str))
		cout << "Формат верный" << endl;
	else
		cout << "Формат не верный" << endl;

	cout << "Введите IP адресс: ";
	cin.getline(str, 255);
	if (is_ip_address(str))
		cout << "Формат верный" << endl;
	else
		cout << "Формат не верный" << endl;


	delete[]str;
	return 0;
}