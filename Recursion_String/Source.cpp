#include <iostream>
#include<Windows.h>
#include<time.h>
#include <stdlib.h>

using namespace std;

/*Реализовать следующие рекурсивные функции для работы со строками:
 1. Подсчитать длину строки
 2. Подсчитать количество слов в строке
 3. Перевести строку в верхний регистр
 4. Перевести строку в нижний регистр
 5. Проверить вхождение указанного символа в строку
 6. Подсчитать количество вхождений указанного символа в строку*/


size_t Strlen(const char* string)//Подсчитать длину строки
{
	return !string || !*string ? 0 : 1 + Strlen(string + 1);
}

int NumberWords(const char* string)//Подсчитать количество слов в строке
{
	int word;
	word = (*string == 32 || *string == 0) ? 1 : 0;
	return *string == 0 ? word : word + NumberWords(string + 1);
}

int QuantitySymbol(const char* string, const char elem)//Подсчёт количества вхождений символа в строку
{
	int sym;
	sym = (elem == *string) ? 1 : 0;
	return (*string == 0) ? sym : sym = sym + QuantitySymbol(string + 1, elem);
}

bool PresenceSymbol(const char* string, const char elem)// Проверить вхождение указанного символа в строку
{
	/*return (elem == *string) ? 1 : (*string == 0) ? 0 : (PresenceSymbol(string + 1, elem) == 1) ? 1:0;*/
	if (elem == *string)
		return 1;
	else
		if (*string == 0)
			return 0;
	if (PresenceSymbol(string + 1, elem) == 1)
		return 1;
}
void UpReg(char* string)//Перевести строку в верхний регистр
{
	if (*string >= 'a' && *string <= 'z' || *string >= 'а' && *string <= 'я')
	{
		*string -= 32;
	}
	if (*string != 0)
		UpReg((string + 1));

}

void DnReg(char* string)//Перевести строку в нижний регистр
{
	if (*string >= 'A' && *string <= 'Z' || *string >= 'А' && *string <= 'Я')
	{
		*string += 32;
	}
	if (*string != 0)
		DnReg((string + 1));

}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char symbol;
	char* string = new char[255];
	cout << "Введите текст (не более 255 символов) : ";
	cin.getline(string, 255);
	cout << "Длинна строки = " << Strlen(string) << endl;
	cout << "Колличество слов с строке = " << NumberWords(string) << endl;
	cout << "Введите символ : ";
	cin >> symbol;
	cout << "Колличество вхождений символа " << symbol << " в строку = " << QuantitySymbol(string, symbol) << endl;
	cout << "Введите символ : ";
	cin >> symbol;
	if (PresenceSymbol(string, symbol))
		cout << "Символ " << symbol << " входит в строку" << endl;
	else
		cout << "Символ " << symbol << " не входит в строку" << endl;

	DnReg(string);
	cout << string << endl;
	UpReg(string);
	cout << string << endl
		;


	delete[] string;


	return 0;
}