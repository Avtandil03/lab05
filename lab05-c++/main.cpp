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


string dec_to_hex(int dec) {

    int size = 0, decTemp = dec;
    
    string hexStr;

    for (size_t i = 0; decTemp > 0; size++)
    {
        decTemp = decTemp / 16;
    }

    int* hexInt = new int[size];
    hexInt[0] = dec;

    for (int i = 1; i < size ; i++)
    {
        hexInt[i] = hexInt[i - 1] / 16;
    }
    for (int j = 0;j < size; j++)
    {

        hexInt[j] = hexInt[j] % 16;

        switch (hexInt[j])
        {
        case 10: hexStr = 'A' + hexStr;
            break;
        case 11: hexStr = 'B' + hexStr;
            break;
        case 12: hexStr = 'C' + hexStr;
            break;
        case 13: hexStr = 'D' + hexStr;
            break;
        case 14: hexStr = 'E' + hexStr;
            break;
        case 15: hexStr = 'F' + hexStr;
            break;
        default:
            if (hexInt[j] < 10)
                hexStr = to_string(hexInt[j]) + hexStr;
            break;
        }
    }
    delete[] hexInt;
    return  hexStr;
}


int main(void)
{
    setlocale(LC_ALL, "Russian");
    int value;
    
    while (true)
    {
        cout << "-------------" << endl;
        cin >> value;

        cout << endl << dec_to_hex(value) << endl;
    }
    system("PAUSE");
}