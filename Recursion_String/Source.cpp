#include <iostream>
#include<Windows.h>
#include<time.h>
#include <stdlib.h>

using namespace std;

/*����������� ��������� ����������� ������� ��� ������ �� ��������:
 1. ���������� ����� ������
 2. ���������� ���������� ���� � ������
 3. ��������� ������ � ������� �������
 4. ��������� ������ � ������ �������
 5. ��������� ��������� ���������� ������� � ������
 6. ���������� ���������� ��������� ���������� ������� � ������*/


size_t Strlen(const char* string)//���������� ����� ������
{
	return !string || !*string ? 0 : 1 + Strlen(string + 1);
}

int NumberWords(const char* string)//���������� ���������� ���� � ������
{
	int word;
	word = (*string == 32 || *string == 0) ? 1 : 0;
	return *string == 0 ? word : word + NumberWords(string + 1);
}

int QuantitySymbol(const char* string, const char elem)//������� ���������� ��������� ������� � ������
{
	int sym;
	sym = (elem == *string) ? 1 : 0;
	return (*string == 0) ? sym : sym = sym + QuantitySymbol(string + 1, elem);
}

bool PresenceSymbol(const char* string, const char elem)// ��������� ��������� ���������� ������� � ������
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
void UpReg(char* string)//��������� ������ � ������� �������
{
	if (*string >= 'a' && *string <= 'z' || *string >= '�' && *string <= '�')
	{
		*string -= 32;
	}
	if (*string != 0)
		UpReg((string + 1));

}

void DnReg(char* string)//��������� ������ � ������ �������
{
	if (*string >= 'A' && *string <= 'Z' || *string >= '�' && *string <= '�')
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
	cout << "������� ����� (�� ����� 255 ��������) : ";
	cin.getline(string, 255);
	cout << "������ ������ = " << Strlen(string) << endl;
	cout << "����������� ���� � ������ = " << NumberWords(string) << endl;
	cout << "������� ������ : ";
	cin >> symbol;
	cout << "����������� ��������� ������� " << symbol << " � ������ = " << QuantitySymbol(string, symbol) << endl;
	cout << "������� ������ : ";
	cin >> symbol;
	if (PresenceSymbol(string, symbol))
		cout << "������ " << symbol << " ������ � ������" << endl;
	else
		cout << "������ " << symbol << " �� ������ � ������" << endl;

	DnReg(string);
	cout << string << endl;
	UpReg(string);
	cout << string << endl
		;


	delete[] string;


	return 0;
}