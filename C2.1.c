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

void CementOrder(int* cementPrice, int* cementCost, int* cementWagons)
{
	printf("Enter the number of tons you want to receive: ");
	int mas;
	int z = scanf("%d", &mas);
	while ((z!=1) || (mas <= 0))
	{
        fflush(stdin);
		printf("Please enter correct data.\n");
		printf("Enter the number of tons you want to receive: ");
		z = scanf("%d", &mas);
	}
	*cementPrice = mas * 230;
	printf("Cost of ordered cement: %d$\n", *cementPrice);
	*cementCost = mas * 70;
	int unfullWagon = mas % 50;
	if (unfullWagon != 0)
	{
		++(*cementWagons);
	}
	*cementWagons += mas / 50;
	printf("Total wagons of cement: %d\n", *cementWagons);
}

void GraviumOrder(int* graviumPrice, int* graviumCost, int* graviumWagons)
{
	printf("Enter the number of tons you want to receive: ");
	int mas;
	int z = scanf("%d", &mas);
	while ((z!=1) || (mas <= 0))
	{
		fflush(stdin);
		printf("Please enter correct data.\n");
		printf("Enter the number of tons you want to receive: ");
		z = scanf("%d", &mas);
	}
	*graviumPrice = mas * 142;
	printf("Cost of ordered gravel: %d$\n", *graviumPrice);
	*graviumCost = mas * 46;
	int unfullWagon = mas % 50;
	if (unfullWagon != 0)
	{
		++(*graviumWagons);
	}
	*graviumWagons += mas / 50;
	printf("Total wagons of gravel: %d\n", *graviumWagons);
}

void ConcreteOrder(int* concretePrice, int* concreteCost, int* concreteWagons)
{
	printf("Enter the number of tons you want to receive: ");
	int mas;
	int z = scanf("%d", &mas);
	while ((z!=1) || (mas <= 0))
	{
		fflush(stdin);
		printf("Please enter correct data.\n");
		printf("Enter the number of tons you want to receive: ");
		z = scanf("%d", &mas);
	}
	*concretePrice = mas * 205;
	printf("Cost of ordered concrete: %d$\n", *concretePrice);
	*concreteCost = mas * 55;
    int unfullWagon = mas % 50;
	if (unfullWagon != 0)
	{
		++(*concreteWagons);
	}
	*concreteWagons += mas / 50;
	printf("Total wagons of concrete: %d\n", *concreteWagons);
}

void CountryChoose(char *country)
{
	printf("Delivery: \n");
	printf("1. Across Belorus \n2. To Russia \n3. To Ukraine \n4. To Moldova \nEnter the number corresponding to the required item: ");
	int num;
	int z = scanf("%d", &num);
	while ((z!=1) || (num <= 0) || (num > 4))
	{
		fflush(stdin);
		printf("Please enter correct data.\n");
		printf("Enter the number corresponding to the item you want: ");
		z = scanf("%d", &num);
	}
	switch (num)
	{
    case 1:
		printf("You have chosen delivery in Belorus.\n");
		country[0] = 'B';
        break;
	case 2:
		printf("You have chosen delivery to Russia.\n");
		country[0] = 'R';
		break;
	case 3:
		printf("You have chosen delivery to Ukraine.\n");
		country[0] = 'U';
		break;
	case 4:
		printf("You have chosen delivery to Moldova.\n");
		country[0] = 'M';
        break;
    }
}

void OptionsTariffs()
{
	printf("Information on what specific tariffs would you like to display? \n");
	printf("1. On cement \n2. On gravel \n3. On concrete \n4. For all \nEnter the number corresponding to the required item: ");
	int num;
	int z = scanf("%d", &num);
	while ((z!=1) || (num <= 0) || (num > 4))
	{
		fflush(stdin);
		printf("Please enter correct data.\n");
		printf("Enter the number corresponding to the item you want: ");
		z = scanf("%d", &num);
	}
	switch (num)
	{
	case 1:
		printf("One ton of cement costs 230$\n");
		break;
	case 2:
		printf("One ton of gravel costs 142$\n");
		break;
	case 3:
		printf("One ton of concrete costs 260$\n");
		break;
	case 4:
		printf("One ton of cement costs 230$\n");
		printf("One ton of gravel costs 142$\n");
		printf("One ton of concrete costs 260$\n");
		break;
	}
}

void OptionsPrice(int cementPrice, int graviumPrice, int concretePrice)
{
	printf("Cost of the ordered materials is: %d$\n", cementPrice + graviumPrice + concretePrice);
}

void OptionsWagons(int cementWagons, int graviumWagons, int concreteWagons)
{
	printf("Number of wagons: %d\n", cementWagons + graviumWagons + concreteWagons);
}

void OptionsTransporation(char* country, int cementWagons, int graviumWagons, int concreteWagons, int* transportationPrice)
{
	int wagons = cementWagons + graviumWagons + concreteWagons;
	printf("Transportation cost: ");
	if (country[0]=='B')
	{
		printf("%d$\n", 200 * wagons);
		*transportationPrice = 200 * wagons;
	}
	else if ((country[0] == 'R') || (country[0] == 'U'))
	{
		printf("%d$\n", 320 * wagons);
		*transportationPrice = 320 * wagons;
	}
	else if (country[0] == 'M')
	{
		printf("%d$\n", 360 * wagons);
		*transportationPrice = 360 * wagons;
	}
    else
	printf("0$\n");
}

void Options(int* cementPrice, int* cementCost, int* cementWagons, int* graviumPrice, int* graviumCost, int* graviumWagons, int* concretePrice, int* concreteCost, int* concreteWagons, int* transportationPrice, char* country)
{
	printf("What specific parameters would you like to display?\n");
	printf("1. Displaying information about tariffs \n2. The cost of the ordered materials \n3. Number of cars \n4. Transportation cost \n5. All \nEnter the number corresponding to the item you want: ");
	int num;
	int z = scanf("%d", &num);
	while ((z!=1) || (num <= 0) || (num > 5))
	{
		fflush(stdin);
		printf("Please enter correct data.\n");
		printf("Enter the number corresponding to the item you want: ");
		z = scanf("%d", &num);
	}
	switch (num)
	{
	case 1:
        OptionsTariffs();
        break;
    case 2:
		OptionsPrice(*cementPrice, *graviumPrice, *concretePrice);
		break;
	case 3:
		OptionsWagons(*cementWagons, *graviumWagons, *concreteWagons);
		break;
	case 4:
		OptionsTransporation(country, *cementWagons, *graviumWagons, *concreteWagons, transportationPrice);
		break;
	case 5:
		OptionsTariffs();
		OptionsPrice(*cementPrice, *graviumPrice, *concretePrice);
		OptionsWagons(*cementWagons, *graviumWagons, *concreteWagons);
		OptionsTransporation(country, *cementWagons, *graviumWagons, *concreteWagons, transportationPrice);
		break;
    }
}

void OrderAcceptance(int cementPrice, int cementCost, int graviumPrice, int graviumCost, int concretePrice, int concreteCost, int transportationPrice)
{
	int a = 0;
	printf("Acceptance of the order. If you are ready to accept the order - enter any number, if not - 0:");
	int z = scanf("%d", &a);
	while (z!=1)
	{
		fflush(stdin);
		printf("Please enter correct data.\n");
		z = scanf("%d", &a);
	}
	if (a != 0)
	{
		int price = cementPrice + graviumPrice + concretePrice;
        int cost = cementCost + graviumCost + concreteCost;
		printf("Cost of your order: %d$\n", price + transportationPrice);
		printf("Enterprise profit: %d$\n", cost);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int cementWagons=0;
    int cementPrice=0;
    int cementCost=0;
    int graviumWagons=0;
	int graviumPrice=0;
    int graviumCost=0;
	int concreteWagons=0;
	int concretePrice=0;
    int concreteCost=0;
    int transportationPrice = 0;
	char country[2];
	int a = 0;
    while (a == 0)
    {
		int b = 0;
		while (b == 0)
        {
			int c;
			int d = 0;
			printf("1. Cement order \n2. Gravel order \n3. Concrete order \n4. Selecting the delivery country \n5. Order parameters \n6. Order confirmation \n7. Author and version information \n8. Exiting the program\n\n");
			printf("Enter the number corresponding to the item you want: ");
			int x = scanf("%d", &c);
			while ((x!=1) || (c <= 0) || (c > 8))
			{
				fflush(stdin);
				printf("Please enter correct data.\n");
				x = scanf("%d", &c);
			}
			switch (c)
            {
			case 1:
				printf("****************************************************************************\n");
				printf("Cement order:\n");
				CementOrder(&cementPrice, &cementCost, &cementWagons);
				b = 0;
				printf("****************************************************************************\n");
				break;
			case 2:
				printf("****************************************************************************\n");
				printf("Gravel order:\n");
				GraviumOrder(&graviumPrice, &graviumCost, &graviumWagons);
				b = 0;
				printf("****************************************************************************\n");
				break;
			case 3:
				printf("****************************************************************************\n");
				printf("Concrete order:\n");
				ConcreteOrder(&concretePrice, &concreteCost, &concreteWagons);
				b = 0;
				printf("****************************************************************************\n");
				break;
			case 4:
				printf("****************************************************************************\n");
				printf("Selecting the delivery country:\n");
				CountryChoose(country);
				b = 0;
				printf("****************************************************************************\n");
				break;
			case 5:
				printf("****************************************************************************\n");
				printf("Order parameters:\n");
				while (d == 0)
                {
					Options(&cementPrice, &cementCost, &cementWagons, &graviumPrice, &graviumCost, &graviumWagons, &concretePrice, &concreteCost, &concreteWagons, &transportationPrice, country);
					printf("If you want to view the parameters again - enter 0, if not - another number");
					int z = scanf("%d", &d);
					while (z!=1)
					{
						fflush(stdin);
						printf("Please enter correct data.\n");
						z = scanf("%d", &d);
					}
				}
				b = 0;
				printf("****************************************************************************\n");
				break;
			case 6:
				printf("****************************************************************************\n");
				OrderAcceptance(cementPrice, cementCost, graviumPrice, graviumCost, concretePrice, concreteCost, transportationPrice);
				b = 0;
				printf("****************************************************************************\n");
				break;
			case 7:
				printf("****************************************************************************\n");
				printf("Version - 1.0, author - Ich.\n");
				b = 0;
				printf("****************************************************************************\n");
				break;
			case 8:
				a = 1;
				b = 1;
                break;
            }
        }
	}
	return 0;
}
