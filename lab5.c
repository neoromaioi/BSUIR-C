#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

struct queue
{
  char qu[100];
  int rear, frnt;
};

void initq(struct queue *q)
{
  q->frnt = 1;
  q->rear = 0;
  return;
}

int isempty(struct queue *q)
{
  if(q->rear < q->frnt)
  {
	return 1;
  }
  else
  {
	return 0;
  }
}

void print(struct queue *q)
{
  int h;
  if(isempty(q)==1)
  {
	printf("Queue is empty/full!\n");
	return;
  }
  for(h = q->frnt; h <= q->rear; h++)
  {
	printf("%c ",q->qu[h]);
  }
  return;
}

int removeq(struct queue *q)
{
  int x, h;
  if(isempty(q)==1)
  {
	printf("Queue is empty/full!\n");
    return 0;
  }
  x = q->qu[q->frnt];
  for(h = q->frnt; h < q->rear; h++)
  {
	q->qu[h] = q->qu[h+1];
  }
  q->rear--;
  return x;
}


void insert(struct queue *q, char x)
{
  if(q->rear < 99)
  {
	q->rear++;
    q->qu[q->rear]=x;
  }
  else
  {
	printf("Queue is empty/full!\n");
  }
  return;
}

struct list
{
  int queueNum;
  char action;
  char symb;
  struct queue *queu;
  struct list *next;
  struct list *prev;
};

struct list* init(int a)
{
  struct list *lst;
  lst = (struct list*)malloc(sizeof(struct list));
  lst->queueNum = a;
  lst->next = NULL;
  lst->prev = NULL;
  struct queue *q;
  q = (struct queue*)malloc(sizeof(struct queue));
  initq(q);
  lst->queu = q;
  return(lst);
}

struct list* addelem(struct list *lst, int number)
{
  struct list *temp, *p;
  temp = (struct list*)malloc(sizeof(struct list));
  p = lst->next;
  lst->next = temp;
  temp->queueNum = number;
  temp->next = p;
  temp->prev = lst;
  if (p != NULL)
  {
	p->prev = temp;
  }
  struct queue *q;
  q = (struct queue*)malloc(sizeof(struct queue));
  initq(q);
  temp->queu = q;
  return(temp);
}

void editque(struct list *lst, int qn, char act, char s)
{
  while(lst != NULL)
  {
	if(lst->queueNum == qn)
	{
	  lst->action = act;
	  lst->symb = s;
	  if(lst->action == 'A')
	  {
		insert(lst->queu, s);
	  }
	  if(lst->action == 'D')
	  {
		removeq(lst->queu);
	  }
	  break;
	}
	lst=lst->next;
  }
  return;
}

void listprint(struct list *lst)
{
  struct list *p;
  p = lst;
  while (p != NULL)
  {
	print(p->queu);
	printf("\n");
	p = p->next;
  }
  return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct list *head, *cur;
	int numb = 1;
	head = init(numb);
	printf("Your first queue was created.\n");
	cur = head;
	int stop = 5;
	while(stop != 0)
	{
	  printf("What do you want?\n1.Create new queue\n2.Add element in queue\n3.Delete first element from queue\n0.End the program\n");
	  int z = scanf("%d", &stop);
	  if((z!=1) || (stop < 0) || (stop > 3))
	  {
		fflush(stdin);
		printf("Please, enter correct data.\n");
		z = scanf("%d", &stop);
	  }
	  if(stop == 1)
	  {
		numb++;
		cur = addelem(cur, numb);
	  }
	  if(stop == 2)
	  {
		printf("Enter queue's number\n");
		int qn;
		int y = scanf("%d", &qn);
		if((y!=1) || (qn < 1) || (qn > numb))
		{
		  fflush(stdin);
		  printf("Please, enter correct data.\n");
		  y = scanf("%d", &qn);
		}
		printf("What character do you want to add?\n");
		fflush(stdin);
		char ch;
		scanf("%c", &ch);
		editque(head, qn, 'A', ch);
		listprint(head);
	  }
	  if(stop == 3)
	  {
		printf("Enter queue's number\n");
		int qm;
		int v = scanf("%d", &qm);
		if((v!=1) || (qm < 1) || (qm > numb))
		{
		  fflush(stdin);
		  printf("Please, enter correct data.\n");
		  v = scanf("%d", &stop);
		}
		editque(head, qm, 'D', ' ');
		listprint(head);
	  }
	  printf("There are %d queues\n", numb);
	}
	getch();
	return 0;
}
