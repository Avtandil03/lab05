#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <conio.h>
#include<string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>



using namespace std;

struct Studetn
{
	char name[16] = "\0";
	uint16_t year;
	float avgScore;
	bool sex;
	uint8_t courseCount;
	void fillInfo() {
			
		cout << "���: ";
		cin >> this->name;

		cout << "��� �����������: ";
		cin >> this->year;

		cout << "������� ����: ";
		cin >> this->avgScore;

		cout << "��� (0 � �������, 1 � �������): ";
		cin >> this->sex;

		cout << "���������� ���������� ������: ";
		cin >> this->courseCount;
	};
};


int main(void)
{
    setlocale(LC_ALL, "Russian");
	
	struct Studetn *starosta;
	bool mode = 0;

	Studetn students[3];
	starosta = &students[0];

	cout << "���������� � ������ ?(1 - ��, 0 || '' - ���): ";
	cin >> mode;

	if (mode == 1)
	{
		for (size_t i = 0; i < sizeof(students) / sizeof(students[0]); i++)
		{
			cout << "���������� �������� � " << i + 1 << ((i == 0) ? "(��������)" : "") << endl;
			students[0].fillInfo();
			cout << "---------------------" << endl;
		}
	}
	else {
		*starosta = { "anna", 2021, 5.0, 0, 23};
		students[1] = { "petr", 2022, 4.3, 1, 9 };
		students[2] = { "gleb", 2018, 3.2, 1, 6 };
	}

	//3.3.1
	cout << endl << "����� �������: " << &students << endl;
	cout << "������ �������: " << sizeof(students) << endl;

	// 3.3 2)
	for (size_t i = 0; i < 3; i++)
	{
		cout << "����� ��������� students[" << i << "] - " << &students[i]<< endl;
		cout << "������ ��������[" << i << "] - " << sizeof(students[i])<< "����" << endl<< endl;		
	}
	 
	//3.3.3
	

	system("pause");

}