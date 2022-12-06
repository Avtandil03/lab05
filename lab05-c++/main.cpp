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
		while (strlen(this->name) < 2 )
		{
			cout << "Имя: ";
			cin >> this->name;
		}
		while (this->year < 1950 || this->year > 2023)
		{
			cout << "Год поступления: ";
			cin >> this->year;
		}
	};
};


int main(void)
{
    setlocale(LC_ALL, "Russian");
	
	struct Studetn *starosta;

	struct Studetn students[3];
	starosta = &students[0];

	starosta->fillInfo();
	

	system("pause");

}