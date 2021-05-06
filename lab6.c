#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <cstddef>
#include <conio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#define MAXWORD 100
struct tnode
{                // узел дерева
  char* word;                  // указатель на строку (слово)
  int count;                   // число вхождений
  struct tnode* left;          // левый потомок
  struct tnode* right;         // правый потомок
};
// Функция добавления узла к дереву
struct tnode* addtree(struct tnode* p, char* w)
{
  int cond;
  if (p == NULL)
  {
    p = (struct tnode*)malloc(sizeof(struct tnode));
	p->word = strdup(w);
	p->count = 1;
    p->left = p->right = NULL;
  }
  else if ((cond = strcmp(w, p->word)) == 0)
  {
	p->count++;
  }
  else if (cond < 0)
  {
	p->left = addtree(p->left, w);
  }
  else
  {
	p->right = addtree(p->right, w);
  }
  return p;
}
// Функция удаления поддерева
void freemem(struct tnode* tree)
{
  if (tree != NULL)
  {
    freemem(tree->left);
    freemem(tree->right);
    free(tree->word);
	free(tree);
  }
}
// Функция вывода дерева
void treeprint(struct tnode* p, int *a)
{
  if (p != NULL)
  {
	treeprint(p->left, a);
	if(*a < p->count)
	{
		*a = p->count;
	}
	//printf("%d %s\n", p->count, p->word);
	treeprint(p->right, a);
  }
}

void treeprintt(struct tnode* p, int a)
{
  if (p != NULL)
  {
	treeprintt(p->left, a);
	if(a == p->count)
	{
		printf("%d %s\n", p->count, p->word);
	}
	//printf("%d %s\n", p->count, p->word);
	treeprintt(p->right, a);
  }
}

void treeprinttt(struct tnode* p, int a)
{
  while(a!=0)
  {
	treeprintt(p, a);
	--a;
  }
}

int _tmain(int argc, _TCHAR* argv[])
{
  struct tnode* root;
  char word[MAXWORD];
  char str[MAXWORD];
  root = NULL;
  FILE *mf;
  mf = fopen("C:\\Users\\Vasya\\LR4.txt", "r");
  if(!mf) exit(1);
  int i = 0;
  char c;
  do
  { 
	fscanf(mf, "%c", &c);
	if((c!='\0') && (c==' ' || c==';' || c==',' || c=='.' || str[i]=='?' || c=='!'))
	{
		word[i]='\0';
		i = 0;
		if (isalpha(word[0]))
		{
			root = addtree(root, word);
        }
		free(word);	
	}
	else
	{
		word[i]=c;
		++i;
	}
  }while(word[0] != '\\');
  int a = 0;
  treeprint(root, &a);
  treeprinttt(root, a);
  freemem(root);
  fclose(mf);
  getch();
  return 0;
}
