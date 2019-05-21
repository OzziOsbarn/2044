/*******************************************************************************
*
* 2019 TUSUR, FB Osipov Daniil
*
* File              : NetBeans.cpp
* Compiler          : NetBeans IDE 8.2 RC
* Version           : 1.0
* Created File      : 19.03.2019
* Last modified     : 19.03.2019
*
* Support mail      : stalkerkop@mail.ru
*
* Target MCU        : MCU: MDR1986
* Description       : breaking a string into substrings 
********************************************************************************/
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "mstn_version.h"
#include "mstn_led.h"
#include "mstn_clk.h"
#include "mstn_usb.h"
int main(int argc, char *argv[])
{
    while(USB_GetStatus() != PERMITTED);
    int Dlin;
    printf("Dlina=");
    scanf("%d", &Dlin);
    int* Mas = new int[Dlin];
    int count;
    int iter = 0;
    for (int i = 0; i < Dlin; i++)
    {
            printf("Mas<<");
            scanf("%d", &count);
            if (count > 7 || count < 0)
            {
                    count = 0;
            }
            Mas[iter] = count;
            iter++;
    }
    //вывод
    printf("[");
    for (int i = 0; i < Dlin; i++)
    {
            printf(" %d ", Mas[i]);
    }printf("]\n");

    int K;
    printf("K byte=");
    scanf("%d", &K);
    int Prob = Dlin;
    count = 0;
    while (count<Dlin)
    {
            printf("[");
            printf(" %d ", count);
            printf(" %d ", count+1);
            printf("][");
            if(K>7)
                    printf(" %d ", 7);
            else
                    printf(" %d ", K);
            printf("][");
            Prob = Dlin - count-K;
            if (Prob < 0)
            {
                    for (int i = count; i < Dlin; i++)
                    {

                            printf(" %d ", Mas[i]);

                    }
                    count = count + K;
                    while (Prob < 0)
                    {
                            printf(" %d ", 0);
                            Prob++;
                    }
            }			
            else
            {
                    for (int i = count; i < count + K; i++)
                    {

                            printf(" %d ", Mas[i]);

                    }
                    count = count + K;
            }
            printf("][");
            printf(" %d ]\n", 0);

    }   
    return EXIT_SUCCESS;
}
