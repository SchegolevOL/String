#include <iostream>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

void PlayingField(char m[3][3]);
bool RecMotion(char m[3][3], char address[2], char s);
int Victory(char m[3][3]);
void FirstMove(char player1[20], char player2[20]);
void CompMove(char m[3][3], char s);




int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));


	char m[3][3] = {};
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			m[i][j] = ' ';
		}
	}
	PlayingField(m);
	char s;
	do
	{
		char player1[20];
		char player2[20] = "��������";
		char address[2];
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				m[i][j] = ' ';
			}
		}
		cout << "\t\txo<<���� �������� ������>>ox" << endl;
		cout << "\t\t\t���� ����:" << endl;
		cout << "\t1.- ���� ������ ���������." << endl;
		cout << "\t2.- ���� ������� ������ ��������." << endl;
		cout << "\t3.- ������� ����." << endl;
		cout << "\t0.- �����." << endl;
		cin >> s;
		switch (s)
		{
		case '1':
		{
			cin.ignore();
			cout << "������� ��� ������  (�� ����� 20 ��������): ";
			cin.getline(player1, 20);

			FirstMove(player1, player2);

			for (size_t i = 0; i < 5; i++)
			{
				if (strcmp(player1, "��������") == 0)
				{
					cout << "�������� ������ ���" << endl;
					CompMove(m, 'x');
					PlayingField(m);

					do
					{
						cout << "����� " << player2 << " �������� ��� : ";
						cin >> address[0];
						cin >> address[1];

					} while (RecMotion(m, address, 'o'));
					PlayingField(m);
				}
				else
				{
					do
					{
						cout << "����� " << player1 << " �������� ��� : ";
						cin >> address[0];
						cin >> address[1];

					} while (RecMotion(m, address, 'x'));
					PlayingField(m);

					cout << "�������� ������ ���" << endl;
					CompMove(m, 'o');
					PlayingField(m);
				}

				if (Victory(m) == 1)
				{
					cout << "������� " << player1 << "!!!!" << endl;
					break;
				}
				else if (Victory(m) == 2)
				{
					cout << "������� " << player2 << "!!!!" << endl;
					break;
				}
				if (i == 4)
				{
					cout << "�����, �������� ������!!!" << endl;
					break;
				}
			}

			break;
		}
		case '2':
		{
			cin.ignore();
			cout << "������� ��� ������ 1 (�� ����� 20 ��������): ";
			cin.getline(player1, 20);
			cout << "������� ��� ������ 2 (�� ����� 20 ��������): ";
			cin.getline(player2, 20);
			FirstMove(player1, player2);

			for (size_t i = 0; i < 5; i++)
			{
				do
				{
					cout << "����� " << player1 << " �������� ��� : ";
					cin >> address[0];
					cin >> address[1];
				} while (RecMotion(m, address, 'x'));

				PlayingField(m);

				if (Victory(m) == 1)
				{
					cout << "������� " << player1 << "!!!!" << endl;
					break;
				}
				else if (Victory(m) == 2)
				{
					cout << "������� " << player2 << "!!!!" << endl;
					break;
				}
				if (i == 4)
				{
					cout << "�����, �������� ������!!!" << endl;
					break;
				}

				do
				{
					cout << "����� " << player2 << " �������� ��� : ";
					cin >> address[0];
					cin >> address[1];

				} while (RecMotion(m, address, 'o'));
				PlayingField(m);
			}
			break;
		}
		case '3':
		{
			PlayingField(m);
			cout << "������ ����� ������� ������� \"x\" ��� \"o\" ��������� ������" << endl;
			cout << "����� \"A, B, C\ � ������ �������� \"1, 2, 3\" ����� ������." << endl;
			cout << "����� ����� �� �������, ������� ������������ �������� �������." << endl;
			cout << "���������� ��� ����� ������� ������ �������� ���������� ������," << endl;
			cout << "������ ��� ��������� ������ ���������� ��� ��������." << endl;
			cout << "������:" << endl;
			cout << "������� ��� ������ ( ������� A 1): " << endl;
			cout << "A 1" << endl;
			m[0][0] = 'x';
			PlayingField(m);
			break;
		}
		case '0':
		{
			cout << "\t�� ������ �������!!!";
			break;
		}
		default:
			cout << "����������� ������� �����." << endl;
			break;
		}

	} while (s != '0');

}

void PlayingField(char m[3][3])
{
	cout << "\t\t\t    1   2   3" << endl;
	cout << "\t\t\t  -------------" << endl;
	cout << "\t\t\tA | " << m[0][0] << " | " << m[0][1] << " | " << m[0][2] << " |" << endl;
	cout << "\t\t\t  -------------" << endl;
	cout << "\t\t\tB | " << m[1][0] << " | " << m[1][1] << " | " << m[1][2] << " | " << endl;
	cout << "\t\t\t  -------------" << endl;
	cout << "\t\t\tC | " << m[2][0] << " | " << m[2][1] << " | " << m[2][2] << " |" << endl;
	cout << "\t\t\t  -------------" << endl;
}

bool RecMotion(char m[3][3], char address[2], char s)
{
	int c = address[0] - 65;
	int r = address[1] - 49;
	if (address[0] > 'C' || address[1] > '3' || address[0] < 'A' || address[1] < '1')
		cout << "����������� ������ ���." << endl;
	else
		if (m[c][r] == 'x' || m[c][r] == 'o')
		{
			cout << "����������� ������ ���." << endl;
		}
		else
		{
			m[c][r] = s;
			return 0;
		}
	return 1;
}

void FirstMove(char player1[20], char player2[20])
{
	char ch[20];
	int rnd = rand() % (2);
	if (rnd)
	{
		cout << "������ ����� �����  " << player2 << " \"x\"" << endl;
		for (size_t i = 0; i < 20; i++)
			ch[i] = player2[i];
		for (size_t i = 0; i < 20; i++)
			player2[i] = player1[i];
		for (size_t i = 0; i < 20; i++)
			player1[i] = ch[i];
	}
	else
		cout << "������ ����� �����  " << player1 << " \"x\"" << endl;
}

int Victory(char m[3][3])
{
	if (m[0][0] + m[0][1] + m[0][2] == 360 || m[1][0] + m[1][1] + m[1][2] == 360 || m[2][0] + m[2][1] + m[2][2] == 360)
		return 1;
	if (m[0][0] + m[1][0] + m[2][0] == 360 || m[0][1] + m[1][1] + m[2][1] == 360 || m[0][2] + m[1][2] + m[2][2] == 360)
		return 1;
	if (m[0][0] + m[1][1] + m[2][2] == 360 || m[0][2] + m[1][1] + m[2][0] == 360)
		return 1;
	if (m[0][0] + m[0][1] + m[0][2] == 333 || m[1][0] + m[1][1] + m[1][2] == 333 || m[2][0] + m[2][1] + m[2][2] == 333)
		return 2;
	if (m[0][0] + m[1][0] + m[2][0] == 333 || m[0][1] + m[1][1] + m[2][1] == 333 || m[0][2] + m[1][2] + m[2][2] == 333)
		return 2;
	if (m[0][0] + m[1][1] + m[2][2] == 333 || m[0][2] + m[1][1] + m[2][0] == 333)
		return 2;
	return 0;
}

void CompMove(char m[3][3], char s)
{
	int k = 0;
	int arr[9];
	int length = 0;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (m[i][j] == ' ')
			{
				arr[k] = i * 10 + j;
				k++;
			}
		}
	}
	int rnd = rand() % k;
	int c = arr[rnd] / 10;
	int r = arr[rnd] % 10;
	m[c][r] = s;
}