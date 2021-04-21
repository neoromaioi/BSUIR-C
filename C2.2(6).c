#pragma hdrstop
#pragma argsused

#include <conio.h>
#include <cmath>
#include <locale.h>
#include <cstdlib>
#include <stdio.h>


#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#define _USE_MATH_DEFINES

double mSin(double x, double e)
{
    int n = 100;
    double s = 0;
    double q = x;
    double counter = 0;
    for (int k = 0; k <= n; k++)
    {
        s += q;
        q *= (-1) * x * x / (2 * k + 2) / (2 * k + 3);
        if ((s > (sin(x) + e)) || (s < (sin(x) - e)))
        {
            counter = k;
        }
    }
	printf("Expression is within the specified error when the n is : %lf\n", counter + 1.0);
    return s;
}

long long int fact(int number)
{
	return (number < 2) ? 1 : number * fact(number - 1);
}

double mySinRec(double x, int number)
{
	if(number == 1)
	{
		return x;
	}
	if(((number-1)/2)%2!=0)
	{
		return mySinRec(x, number-2)-(pow(x, number)/fact(number));
	}
	else
	{
		return mySinRec(x, number-2)+(pow(x, number)/fact(number));
	}
	return x;
}

int main()
{
	setlocale(LC_ALL,"Russian");
	double e = 0.000001;
	double mySin = 0;
	printf("Cmath's sin of pi/6 is: %lf\n", sin((M_PI)/6));
	mySin = mSin((M_PI) / 6, e);
	printf("My sin of pi/6 is: %lf\n", mySin);
    mySin = mySinRec((M_PI) / 6, 57);
	printf("Recurtion's sin of pi/6 is: %lf\n", mySin);
	printf("Cmath's sin of pi/4 is: %lf\n", sin(M_PI_4));
	mySin = mSin(M_PI_4, e);
	printf("My sin of pi/4 is: %lf\n", mySin);
	mySin = mySinRec(M_PI_4, 57);
	printf("Recurtion's sin of pi/4 is: %lf\n", mySin);
	printf("Cmath's sin of pi/3 is: %lf\n", sin((M_PI)/3));
    mySin = mSin((M_PI) / 3, e);
	printf("My sin of pi/3 is: %lf\n", mySin);
	mySin = mySinRec((M_PI) / 3, 57);
	printf("Recurtion's sin of pi/3 is: %lf\n", mySin);
	printf("Cmath's sin of pi/2 is: %lf\n", sin(M_PI_2));
	mySin = mSin(M_PI_2, e);
	printf("My sin of pi/2 is: %lf\n", mySin);
	mySin = mySinRec(M_PI_2, 57);
	printf("Recurtion's sin of pi/2 is: %lf\n", mySin);
	getch();
}
