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

    unsigned int size = 0, decTemp = dec;
    
    string hexStr;

    for (size_t i = 0; decTemp > 0; size++)
    {
        decTemp = decTemp / 16;
    }

    unsigned int* hexInt = new unsigned int[size];
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
    if (hexStr.length() % 2 == 1) {
        hexStr = '0' + hexStr;
    }

    delete[] hexInt;
    string tempStr;
    for (size_t i = 0; i < hexStr.length(); i= i+2)
    {
        tempStr = hexStr[i + 1] + tempStr;
        tempStr = hexStr[i] + tempStr;
        tempStr = " " + tempStr;
    }
    return  tempStr;
}

void setNullToArr(unsigned int arr[] , int value) {

    for (size_t i = 0; i < arr[65]; i++)
    {
        arr[arr[65] - i + value] = arr[arr[65] - i];
    }
    for (size_t i = 0; i < value; i++)
    {
        arr[i] = 0;
    }
}

void coutArr(unsigned int arr[], int value) {
    for (size_t i = 0; i <= value; i++)
    {
        cout << arr[i];
        if ((value - i) % 8 == 0)
            cout << ' ';
    }
}

void dec_to_bin(int dec1 , int dec2 , char _operator)
{
    string binStr;

    
    unsigned int  arr[3][66], dec[2] = {dec1, dec2}, count;
    for (size_t j = 0; j < 2; j++)
    {
        int i = 0, r;

        while (dec[j] != 0)
        {
            r = dec[j] % 2;
            arr[j][i++] = r;
            dec[j] /= 2;
        }

        arr[j][65] = i - 1;
    }

    if ((arr[0][65] > arr[1][65])) {
        arr[0][64] = arr[0][65] - arr[1][65];
        arr[1][65] = arr[0][65];

        setNullToArr(arr[1], arr[0][64]);

    }
    else if ((arr[0][65] < arr[1][65])) {
        arr[0][64] = arr[1][65] - arr[0][65];
        arr[0][65] = arr[1][65];

        setNullToArr(arr[0], arr[0][64]);
    }
    else if ((arr[0][65] < arr[1][65])) {
        arr[0][64] = 0;
        arr[0][65] = arr[1][65];
    }

    for (size_t i = 0; i <= arr[0][65]; i++)
    {
        if (_operator == '&') {
            arr[2][arr[0][65] - i] = arr[0][arr[0][65] - i] & arr[1][arr[1][65] - i];
        } 
        else if (_operator == '|')
        {
            arr[2][arr[0][65] - i] = arr[0][arr[0][65] - i] | arr[1][arr[1][65] - i];
        }
        else
        {
            arr[2][arr[0][65] - i] = arr[0][arr[0][65] - i] ^ arr[1][arr[1][65] - i];
        }

       
    }


    coutArr(arr[0], arr[0][65]);
    cout << _operator << endl;
    coutArr(arr[1], arr[0][65]);
    cout << "=" << endl<< endl;
    coutArr(arr[2], arr[0][65]);

}


int main(void)
{
    setlocale(LC_ALL, "Russian");
    unsigned int operand1, operand2;
    char _operator = ' ';
   
    cout << "Операнд-1: ";
    cin >> operand1;
    while (_operator != '&' && _operator != '|' && _operator != '^' )
    {
        cout << endl << "Побитовый оператор( &, |, ^): " ;
        cin >> _operator;
    }
    cout << endl << "Операнд-2: ";
    cin >> operand2;
    cout << endl;

    cout << dec_to_hex(operand1) << ' ' << _operator << ' ' << dec_to_hex(operand2) << " =" << endl<<endl;
    dec_to_bin(operand1, operand2, _operator);
}