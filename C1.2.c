#pragma hdrstop
#pragma argsused

#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

int Comparison(char* firstNumber, int n, char* secondNumber, int m)
{
	int counter1 = 0, counter2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (firstNumber[i] == '1')
		{
			counter1++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (secondNumber[i] == '1')
		{
			counter2++;
		}
	}
	if (counter1 >= counter2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int ConvertToBinary(int current, int last)
{
	int curr = current;
	int lastt = last;
	int element;
	char binaryForm1[86] = "";
	for (int i = 0; current; i++)
	{
		element = current % 2;
		current /= 2;
		binaryForm1[i] = element + '0';
	}
	char binaryForm2[86] = "";
	element = 0;
	for (int i = 0; last; i++)
	{
		element = last % 2;
		last /= 2;
		binaryForm2[i] = element + '0';
	}
	if (Comparison(binaryForm1, 86, binaryForm2, 86) == 1)
	{
		return curr;
	}
	else
	{
		return lastt;
	}
}

 void SoughtToBinary(int sought)
{
	int element;
	char binaryForm[86] = "";
	int counter = 0;
	for (int i = 0; sought; i++)
	{
		element = sought % 2;
		sought /= 2;
		binaryForm[i] = element + '0';
		++counter;
	}
	for (int i = counter; i >= 0; i--)
	{
		printf("%c", binaryForm[i]);
	}
}

int main()
{
	int min, max, current, sought;
	printf("Please enter the boundaries of your interval\n");
	printf("minimal: ");
	int z = scanf("%d", &min);
	while (z!=1)
	{
		fflush(stdin);
		printf("Please, enter correct boundaries.\n");
		printf("minimal: ");
		z = scanf("%d", &min);
	}
	printf("maximum: ");
	int x = scanf("%d", &max);
	while (x!=1)
	{
		fflush(stdin);
		printf("Please, enter correct boundaries.\n");
		printf("minimal: ");
		x = scanf("%d", &min);
	}
	while ((min == max)||(min<=0)||(max<=0))
	{
		printf("Please, enter correct boundaries.\n");
		printf("minimal: ");
		z = scanf("%d", &min);
        while (z!=1)
		{
			fflush(stdin);
			printf("Please, enter correct boundaries.\n");
			printf("minimal: ");
			z = scanf("%d", &min);
		}
		printf("maximum: ");
		x = scanf("%d", &max);
        while (x!=1)
		{
			fflush(stdin);
			printf("Please, enter correct boundaries.\n");
			printf("minimal: ");
			x = scanf("%d", &min);
		}
	}
	sought = min;
	for (current = min+1; current <= max; current++)
	{
		sought=ConvertToBinary(current, sought);
	}
	printf("Number with the highest count of 1 in binary system is   %d\n", sought);
	printf("Its binary representation: ");
	SoughtToBinary(sought);
	getch();
	return 0;
}
