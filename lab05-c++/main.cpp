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
			
		cout << "Имя: ";
		cin >> this->name;

		cout << "Год поступления: ";
		cin >> this->year;

		cout << "Средний балл: ";
		cin >> this->avgScore;

		cout << "Пол (0 — женский, 1 — мужской): ";
		cin >> this->sex;

		cout << "Количество пройденных курсов: ";
		cin >> this->courseCount;
	};
};

void logMemory(Studetn student) {
    cout << "Имя: " << student.name<< "=" << &student.name << endl;
    cout << "Год поступления: " << student.year << "=" << &student.year << endl;
    cout << "Средний балл: " << student.avgScore << "=" << &student.avgScore << endl;
    cout << "Количество пройденных курсов: " << student.courseCount << "=" << &student.courseCount << endl<< endl;
}

void logOffset(Studetn student) {
    cout << "Имя: " << offsetof(struct Studetn, name) << endl;
    cout << "Год поступления: " << offsetof(struct Studetn, year) << endl;
    cout << "Средний балл: " << offsetof(struct Studetn, avgScore) << endl;
    cout << "Количество пройденных курсов: " << "=" << offsetof(struct Studetn, courseCount) << endl << endl;
}


int main(void)
{
    setlocale(LC_ALL, "Russian");
	
	struct Studetn *starosta;
	bool mode = 0;

	Studetn students[3];
	starosta = &students[0];

	cout << "Заполнение в ручную ?(1 - да, 0 || '' - нет): ";
	cin >> mode;

	if (mode == 1)
	{
		for (size_t i = 0; i < sizeof(students) / sizeof(students[0]); i++)
		{
			cout << "Заполнение студента № " << i + 1 << ((i == 0) ? "(староста)" : "") << endl;
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
	cout << endl << "Адрес массива: " << &students << endl;
	cout << "Размер массива: " << sizeof(students) << endl;

	// 3.3 2)
	for (size_t i = 0; i < 3; i++)
	{
		cout << "Адрес структуры students[" << i << "] - " << &students[i]<< endl;
		cout << "Размер элемента[" << i << "] - " << sizeof(students[i])<< "байт" << endl<< endl;		
	}
	 
	//3.3.3 адрес, смещение от начала структуры, размер, шестнадцатеричное и двоичное представление;
    
    logMemory(students[1]);
    logOffset(students[1]);
    

	

	system("pause");

}