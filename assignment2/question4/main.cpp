#include <stdio.h>
#include <string.h>
#include "crc.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    static char answer[] = "67D7A30E38974FE4F854F6D644B4CB18";
    static char str[] = "123456789";
    crc_t answerCrc;

    answerCrc = crc_init();
    answerCrc = crc_update(answerCrc, (unsigned char *)answer, strlen(answer));
    answerCrc = crc_finalize(answerCrc);

    printf("0x%lx\n", (unsigned long)answerCrc);

    long int count = 0;

    char ascii[] = " !\"#$%&\\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

    int size = sizeof(ascii);
    cout << "size is " << size << endl;

    while (true) {
        string text = "";
        long int temp = count;
        while (true) {
            char leastSignificantDigit = ascii[temp % size];
            text += leastSignificantDigit;
            if (temp / size <= 1) {
                break;
            }
            temp >>= 7;
        }
        char current[1024];
        strncpy(current, text.c_str(), sizeof(current));
        current[sizeof(current) - 1] = 0;
        crc_t currentCrc;
        currentCrc = crc_init();
        currentCrc = crc_update(currentCrc, (unsigned char *)current, strlen(current));
        currentCrc = crc_finalize(currentCrc);
        if (count % 9999999 == 0) {
            printf("count: %ld - ", count);
            cout << current << endl;
            printf("0x%lx\n", (unsigned long)currentCrc);
        }
        if ((unsigned long)currentCrc == (unsigned long)answerCrc) {
            cout << "You are done" << endl;
            cout << current << endl;
            printf("0x%lx\n", (unsigned long)answerCrc);
            ofstream outfile;
            outfile.open("answer.dat", ios::binary | ios::out);
            outfile.write(reinterpret_cast<char*>(&count), sizeof(count)); // sizeof can take a type
            outfile.close();
            break;
        }
        count++;
    }


    return 0;
}

//answer is 1192892578