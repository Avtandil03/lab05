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
    int hex = 0, hex1 = 0;
    string hexStr;
    for (; hex <= dec - 16; hex1++)
    {
        hex = hex + 16;
    }
    hex = dec - hex;
    switch (hex)
    {
        case 10: hexStr = 'A';
            break;
        case 11: hexStr = 'B';
            break;
        case 12: hexStr = 'C';
            break;
        case 13: hexStr = 'D';
            break;
        case 14: hexStr = 'E';
            break;
        case 15: hexStr = 'F';
            break;
    default:
        if (hex < 10)
            hexStr = to_string(hex);
        break;
    }
    return to_string(hex1) + hexStr;
}


int main(void)
{
    setlocale(LC_ALL, "Russian");
    int value;
    cin >> value;
    
    cout << endl << dec_to_hex(value)<< endl;
    system("PAUSE");
}