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

	Studetn students[3];
	starosta = &students[0];
	for (size_t i = 0; i < sizeof(students)/sizeof(students[0]); i++)
	{
		cout << "���������� �������� � " << i + 1 << ((i == 0) ? "(��������)" : "") << endl;
		students[0].fillInfo();
		cout << "---------------------"<<endl;
	}
	

	system("pause");

}