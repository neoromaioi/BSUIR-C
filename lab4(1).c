#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <string.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

int _tmain(int argc, _TCHAR* argv[]) 
{
	int i = 0, max = 0, length;
	int similar = 0;
	char c, word[80], maxWord[80];
	printf("Your text:\n");
	while((c = getchar()) != EOF)
	{
		if(c != ' ' && c != '\n' && c != '\t' && c != ',' && c != '.' && c != '!' && c != '?'&& c != ';' && c != ':')
		{
			word[i] = c;
			i++;
		}
		else
		{
            similar = 0;
			word[i] = '\0';
			length = i;
			i = 0;
			for(int k = 0; k < length; k++)
			{
				for(int j = k; j < length; j++)
				{
					if(word[j] == word[k] && j != k)
					{
						similar = 1;
						break;
					}
				}
				if(k == length - 1 && k > max && similar == 0)
				{
					max = k;
					for(int z = 0; z <= max; z++)
					{
						maxWord[z] = word[z];
					}
					maxWord[max+1] = '\0';
					similar = 0;
				}
			}
		}
    }
	printf("%s", maxWord);
	getch();
	return 0;
}
