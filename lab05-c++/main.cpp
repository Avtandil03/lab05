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

//void print_bits(void* buf, size_t size_in_bytes)
//{
//    char* ptr = (char*)buf;
//
//    for (size_t i = 0; i < size_in_bytes; i++) {
//        for (short j = 7; j >= 0; j--) {
//            printf("%d", (ptr[i] >> j) & 1);
//        }
//        printf(" ");
//    }
//    printf("\n");
//}
//
//int main(void)
//{
//    size_t n;
//    scanf("%d", &n);
//    print_bits(&n, sizeof(n));
//    system("PAUSE");
//}

void print_in_hex(int data[], size_t size)
{
    uint16_t endlHex = 0;

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

int main(void)
{
    setlocale(LC_ALL, "Russian");
    const size_t size = 16;
    int data[size] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
   
    print_in_hex(data, size);

    cout << endl;
    system("PAUSE");
}