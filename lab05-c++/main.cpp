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

void print_in_hex(int data[], size_t size)
{
    uint8_t endlHex = 0;

    for (size_t i = 0; i < size; i++)
    {        
        cout << hex << setfill('0') << setw(2) << data[i] << " ";
        endlHex++;
        if (endlHex >= 16)
        {
            cout << endl;
            endlHex = 0;
        }
    }              
}

void print_in_binary(int data[], size_t size)
{
    uint8_t endlBin = 0;

    for (size_t j = 0; j < size; j++)
    {
        unsigned int i ;
        i = 1 << (sizeof(uint8_t) * 8 - 1);

        while (i > 0)
        {
            if (data[j] & i)
                printf("1");
            else
                printf("0");
            i >>= 1;
        }
        cout<< " ";
        endlBin++;
        if (endlBin >= 4)
        {
            cout << endl;
            endlBin = 0;
        }
    }    
}

int main(void)
{
    setlocale(LC_ALL, "Russian");
    const size_t size = 16;
    int data[size] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    
    cout <<endl<< "Â hex:" << endl;
    print_in_hex(data, size);
    cout <<endl<< "Â binary:" << endl;
    print_in_binary(data, size);        
    cout << endl;
}