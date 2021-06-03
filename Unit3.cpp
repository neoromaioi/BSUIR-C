//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int arr[14];
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	int n;
	int m=0;
	srand(8);
	StringGrid1->ColCount = 15;
	StringGrid1->RowCount = 15;
	for(int i = 1; i < 15; i++)
	{
		StringGrid1->Cells[0][i] = "Row " + IntToStr(i);
		StringGrid1->Cells[i][0] = "Column " + IntToStr(i);
	}
	/*for(int k = 1; k < 15; k++)
	{
		for(int j = 1; j < 15; j++)
		{
			StringGrid1->Cells[k][j] = IntToStr(m);
		}
	}*/
	for(int i = 1; i < 15; i++)
	{
		n = 1 + rand()%14;
		for(int j = 1; j < i; j++)
		{
			 while(StringGrid1->Cells[j][n] != "" && n == StrToInt(StringGrid1->Cells[j][n]))
			 {
				n = 1 + rand()%14;
				j = 1;
			 }
		}
		StringGrid1->Cells[i][n] = IntToStr(n);
		arr[i-1] = n;
	}
	/*for(int k = 1; k < 15; k++)
	{
		for(int j = 1; j < 15; j++)
		{
			if(StringGrid1->Cells[k][j] == IntToStr(0))
				StringGrid1->Cells[k][j] = "";
		}
	}*/
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	for(int k = 1; k < 15; k++)
	{
		for(int j = 1; j < 15; j++)
		{
			StringGrid1->Cells[k][j] = "";
		}
	}
	int numbers[14];
	for(int i = 0; i < 14; i++)
	{
		if(arr[i])
		numbers[i] = arr[i];
	}
    for(int k = 1; k < 15; k++)
	{
		for(int j = 1; j < 15; j++)
		{
			StringGrid1->Cells[k][j] = "";
		}
	}
    int *nums = new int[14];
	int* number = new int[14];
	switch(RadioGroup1->ItemIndex)
	{
		case 0:
		bubbleSort(StringGrid1, numbers, 14);
		break;
		case 1:
		quickSort(StringGrid1, numbers, 0, 13);
		/*for(int i = 1, j = 0; i < 15; i++, j++)
		{
			StringGrid1->Cells[i][numbers[j]] = IntToStr(numbers[j]);
		}*/
		break;
		case 2:
		//merge(StringGrid1, numbers, 14);
		/*int *nums = new int[14];
		int* number = new int[14];*/
		/*for(int i = 0; i < 14; i++)
		{
			if(numbers[i])
			nums[i] = numbers[i];
		}*/
		number = merge_sort(StringGrid1, numbers, nums, 0, 13);
		break;
		case 3:
		selectionSort(StringGrid1, numbers, 14);
		break;
		case 4:
        insertionSort(StringGrid1, numbers, 14);
		break;
		case 5:
		sort(StringGrid1, numbers, 14);
		break;
		case 6:
		shellSort(StringGrid1, numbers, 14);
		break;
		case 7:
        shakerSort(StringGrid1, numbers, 14);
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioGroup1Click(TObject *Sender)
{
	for(int k = 1; k < 15; k++)
	{
		for(int j = 1; j < 15; j++)
		{
			StringGrid1->Cells[k][j] = "";
		}
	}
    for(int i = 1, j = 0; i < 15; i++, j++)
	{
		StringGrid1->Cells[i][arr[j]] = IntToStr(arr[j]);
	}
}
//---------------------------------------------------------------------------


