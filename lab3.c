#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

int _tmain(int argc, _TCHAR* argv[])
{
  int i, j;
  int chessField[8][8];
  for ( i = 0; i < 8; i++ )
  {
	for ( j = 0; j < 8; j++ )
	{
                chessField[i][j] = 0;
	}
  }
  printf("  A B C D E F G H\n");
  int n = 1;
  for ( i = 0; i < 8; i++ )
  {
	printf("%d", n);
	++n;
		for ( j = 0; j < 8; j++ )
        {
                printf( " %d", chessField[i][j]);
        }
        printf( "\n" );
  }
  n=0;
  //char firstQueen[2];
  char* firstQueen;
  firstQueen = (char*)malloc(3);
  printf( "First Queen coordinates: " );
  int x = scanf("%2s", firstQueen);
  while (firstQueen[0]<'A'||firstQueen[0]>'H')
  {
	fflush(stdin);
	printf("Please, enter correct value.\n");
	printf("First Queen coordinates: ");
	x = scanf("%2s", firstQueen);
  }
  while (firstQueen[1]<'1'||firstQueen[1]>'8')
  {
	fflush(stdin);
	printf("Please, enter correct value.\n");
	printf("First Queen coordinates: ");
	x = scanf("%2s", firstQueen);
  }
  //char secondQueen[2];
  char* secondQueen;
  secondQueen = (char*)malloc(3);
  printf( "Second Queen coordinates: " );
  int y = scanf("%2s", secondQueen);
  while (secondQueen[0]<'A'||secondQueen[0]>'H')
  {
	fflush(stdin);
	printf("Please, enter correct value.\n");
	printf("Second Queen coordinates: ");
	y = scanf("%2s", secondQueen);
  }
  while (secondQueen[1]<'1'||secondQueen[1]>'8')
  {
	fflush(stdin);
	printf("Please, enter correct value.\n");
	printf("Second Queen coordinates: ");
	y = scanf("%2s", secondQueen);
  }
  //char King[2];
  char* King;
  King = (char*)malloc(3);
  printf( "King coordinates: " );
  int z = scanf("%2s", King);
  while (King[0]<'A'||King[0]>'H')
  {
	fflush(stdin);
	printf("Please, enter correct value.\n");
	printf("King coordinates: ");
	z = scanf("%2s", King);
  }
  while (King[1]<'1'||King[1]>'8')
  {
	fflush(stdin);
	printf("Please, enter correct value.\n");
	printf("King coordinates: ");
	z = scanf("%2s", King);
  }
  int a, b;
  b = firstQueen[0] - 'A';
  a = firstQueen[1] - '1';
  chessField[a][b] = 2;
  a = secondQueen[1] - '1';
  chessField[a][b] = 2;
  b = King[0] - 'A';
  a = King[1] - '1';
  chessField[a][b] = 1;
  printf("  A B C D E F G H\n");
  for ( i = 0; i < 8; i++ )
  {
  	++n;
	printf("%d", n);
		for ( j = 0; j < 8; j++ )
		{
				printf( " %d", chessField[i][j]);
		}
		printf( "\n" );
  }
  n=0;
   for ( i = 0; i < 8; i++ )
  {
		if(chessField[a][i]==2)
		{
			if((firstQueen[1] == i + '1')&&(firstQueen[0] == j + 'A'))
			{
				printf("Under attack by the first Queen \n");
			}
			else
			{
				printf("Under attack by the second Queen \n");
			}
			break;
		}
        if(chessField[i][b]==2)
		{
			if((firstQueen[1] == i + '1')&&(firstQueen[0] == j + 'A'))
			{
				printf("Under attack by the first Queen \n");
			}
			else
			{
				printf("Under attack by the second Queen \n");
			}
			break;
		}
  }
  for(int i = a + 1, j = b + 1; i < 8, j < 8; i++, j++)
  {
	  if(chessField[i][j] == 2)
	  {
			if((firstQueen[1] == i + '1')&&(firstQueen[0] == j + 'A'))
			{
				printf("Under attack by the first Queen \n");
			}
			else
			{
				printf("Under attack by the second Queen \n");
			}
			break;
	  }
  }
  for(int i = a - 1, j = b - 1; i >= 0, j >= 0; i--, j--)
  {
	  if(chessField[i][j] == 2)
	  {
			if((firstQueen[1] == i + '1')&&(firstQueen[0] == j + 'A'))
			{
				printf("Under attack by the first Queen \n");
			}
			else
			{
				printf("Under attack by the second Queen \n");
			}
			break;
	  }
  }

  for(int i = a + 1, j = b - 1; i < 8, j >= 0; i++, j--)
  {
	  if(chessField[i][j] == 2)
	  {
			if((firstQueen[1] == i + '1')&&(firstQueen[0] == j + 'A'))
			{
				printf("Under attack by the first Queen \n");
			}
			else
			{
				printf("Under attack by the second Queen \n");
			}
			break;
	  }
  }
  for(int i = a - 1, j = b + 1; i >= 0, j < 8; i--, j++)
  {
	  if(chessField[i][j] == 2)
	  {
			if((firstQueen[1] == i + '1')&&(firstQueen[0] == j + 'A'))
			{
				printf("Under attack by the first Queen \n");
			}
			else
			{
				printf("Under attack by the second Queen \n");
			}
			break;
	  }
  }
  getch();
  return 0;
}

