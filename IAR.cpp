/*******************************************************************************
*
* 2019 TUSUR, FB Osipov Daniil
*
* File              : IAR.cpp
* Compiler          : IAR Embedded Workbench
* Version           : 1.0
* Created File      : 19.03.2019
* Last modified     : 19.03.2019
*
* Support mail      : stalkerkop@mail.ru
*
* Target MCU        : MCU: MDR1986
* Description       : breaking a string into substrings 
********************************************************************************/
#include<stdio.h>
#include<iostream>


int main()
{
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
	
	system("pause");
	return 0;
}