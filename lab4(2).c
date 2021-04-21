#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define LEN 256
int main()
{
	int count[LEN];
	int i,j,k,l,m,p;
	char str[10000];
	char word[LEN];
	char dict[LEN][LEN];
	char dictTemp[LEN][LEN];
	str[i]='\0';
	i=0;
	k=0;
	FILE *fp;
	fp = fopen("C:\\Users\\Vasya\\LR4.txt", "r");
	if(!fp) exit(1);
	while (fgets(str, 10000, fp) != NULL)
	{
	while (str[i]!='\0')
	{
		while ((str[i]!='\0') && (str[i]==' ' || str[i]==';' || str[i]==',' || str[i]=='.' || str[i]=='?' || str[i]=='!'))
		{
			++i;
		}
		if(str[i]=='\0')
		{
			break;
		}
		j=0;
		for (;str[i]!='\0' && str[i]!=' ' && str[i]!=';' && str[i]!=',' && str[i]!='.' && str[i]!='?' && str[i]!='!'; i++)
		{
			word[j]=str[i];
			j++;
		}
		word[j]='\0';
		l=0;
		p=1;
		while (l<k)
		{
			for(m=0;dict[l][m]!='\0';m++);
			if(m==j)
			{
				for(m=0;m<j;m++)
				{
					if(word[m]!=dict[l][m])
					{
						break;
					}
				}
				if(m==j)
				{
					count[l]++;
					p=0;
				}
			}
			if(p==0)
			{
				break;
			}
            l++;
        }
		if (p==1) {
			for(m=0;m<j;m++)
			{
				dict[k][m]=word[m];
			}
			dict[k][m]='\0';
			count[k]=1;
			k++;
		}
	}
	}
	printf("Words and the frequency of their occurrence in the sentence:\n");
	int countTemp;
	for(int a=0;a<k;a++)
	{
		for(int b=0;b<k;b++)
		{
			if(count[a]>count[b])
			{
				countTemp = count[a];
				count[a] = count[b];
				count[b] = countTemp;
				for(m=0;m<255;m++)
				{
					dictTemp[0][m]=dict[a][m];
					dict[a][m]=dict[b][m];
					dict[b][m]=dictTemp[0][m];
                    dictTemp[0][m]='\0';
				}
            }
		}
	}
	for (i=0;i<k;i++)
	{
		if(i==20)
		{
			break;
		}
		printf("%3d - %s \n", count[i], dict[i]);
	}
	fclose(fp);
	getch();
    return 0;
}

