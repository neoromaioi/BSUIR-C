//---------------------------------------------------------------------------
#include <vcl.h>
#include <Vcl.Grids.hpp>
#ifndef Kurssov2H
#define Kurssov2H
//---------------------------------------------------------------------------
#endif

void quickSort(TStringGrid *SG1, int *numbers, int left, int right)
{
  int pivot;
  int l_hold = left;
  int r_hold = right;
  pivot = numbers[left];
  while (left < right)
  {
	while ((numbers[right] >= pivot) && (left < right))
	  right--;
	if (left != right)
    {
	  numbers[left] = numbers[right];
	  left++;
    }
	while ((numbers[left] <= pivot) && (left < right))
	  left++;
	if (left != right)
    {
	  numbers[right] = numbers[left];
	  right--;
	}
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  Sleep(1000);
  Application->ProcessMessages();
  for(int k = 1; k < 15; k++)
	{
		for(int j = 1; j < 15; j++)
		{
			SG1->Cells[k][j] = "";
		}
	}
  for(int i = 1, j = 0; i < 15; i++, j++)
		{
			SG1->Cells[i][numbers[j]] = IntToStr(numbers[j]);
		}
  if (left < pivot)
	quickSort(SG1, numbers, left, pivot - 1);
  if (right > pivot)
	quickSort(SG1, numbers, pivot + 1, right);
}

void bubbleSort(TStringGrid* SG1, int *num, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
	for (int j = (size - 1); j > i; j--)
	{
	  if (num[j - 1] > num[j])
	  {
		int temp = num[j - 1];
		num[j - 1] = num[j];
		num[j] = temp;
		Sleep(500);
		Application->ProcessMessages();
		 for(int k = 1; k < 15; k++)
		{
			for(int l = 1; l < 15; l++)
			{
				SG1->Cells[k][l] = "";
			}
		}
		 for(int o = 1, k = 0; o < 15; o++, k++)
		{
			SG1->Cells[o][num[k]] = IntToStr(num[k]);
		}
	  }
    }
  }
}

int* merge_sort(TStringGrid* SG1, int *up, int *down, unsigned int left, unsigned int right)
{
    if (left == right)
    {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = (left + right) / 2;

	int *l_buff = merge_sort(SG1, up, down, left, middle);
	int *r_buff = merge_sort(SG1, up, down, middle + 1, right);

    int *target = l_buff == up ? down : up;

    unsigned int l_cur = left, r_cur = middle + 1;
    for (unsigned int i = left; i <= right; i++)
    {
        if (l_cur <= middle && r_cur <= right)
        {
            if (l_buff[l_cur] < r_buff[r_cur])
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= middle)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
		}
		Sleep(500);
		Application->ProcessMessages();
		for(int k = 1; k < 15; k++)
		{
			for(int l = 1; l < 15; l++)
			{
				 SG1->Cells[k][l] = "";
			}
		}
		for(int o = 1, k = 0; o < 15; o++, k++)
		{
			SG1->Cells[o][target[k]] = IntToStr(target[k]);
		}
    }
	return target;
}

void selectionSort(TStringGrid* SG1, int *num, int size)
{
  int min, temp; // для поиска минимального элемента и для обмена
  for (int i = 0; i < size - 1; i++)
  {
    min = i; // запоминаем индекс текущего элемента
    // ищем минимальный элемент чтобы поместить на место i-ого
    for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
    {
      if (num[j] < num[min]) // если элемент меньше минимального,
        min = j;       // запоминаем его индекс в min
    }
    temp = num[i];      // меняем местами i-ый и минимальный элементы
    num[i] = num[min];
	num[min] = temp;
	Sleep(500);
	Application->ProcessMessages();
	for(int k = 1; k < 15; k++)
	{
		for(int l = 1; l < 15; l++)
		{
			SG1->Cells[k][l] = "";
		}
	}
	for(int o = 1, k = 0; o < 15; o++, k++)
	{
		SG1->Cells[o][num[k]] = IntToStr(num[k]);
	}
  }
}

void insertionSort(TStringGrid* SG1, int *num, int size)
{
  // Для всех элементов кроме начального
  for (int i = 1; i < size; i++)
  {
    int value = num[i]; // запоминаем значение элемента
    int index = i;     // и его индекс
    while ((index > 0) && (num[index - 1] > value))
    {   // смещаем другие элементы к концу массива пока они меньше index
      num[index] = num[index - 1];
      index--;    // смещаем просмотр к началу массива
    }
	num[index] = value; // рассматриваемый элемент помещаем на освободившееся место
	Sleep(500);
	Application->ProcessMessages();
	for(int k = 1; k < 15; k++)
	{
		for(int l = 1; l < 15; l++)
		{
			SG1->Cells[k][l] = "";
		}
	}
	for(int o = 1, k = 0; o < 15; o++, k++)
	{
		SG1->Cells[o][num[k]] = IntToStr(num[k]);
	}
  }
}

void sort(TStringGrid* SG1, int *array, int size)
{
	if (!array || !size)
		return;
	int jump = size;
	bool swapped = true;
	while (jump > 1 || swapped)
	{
		if (jump > 1)
		{
			jump = (int)(jump / 1.25);
		}
		swapped = false;
		for (int i = 0; i + jump < size; i++)
		{
			if (array[i] > array[i + jump])
			{
				int tmp=array[i];
				array[i]=array[i+jump];
				array[i+jump]=tmp;
				swapped = true;
			}
		}
        Sleep(500);
		Application->ProcessMessages();
		for(int i = 1; i < 15; i++)
		{
			for(int l = 1; l < 15; l++)
			{
				SG1->Cells[i][l] = "";
			}
		}
		for(int o = 1, i = 0; o < 15; o++, i++)
		{
			SG1->Cells[o][array[i]] = IntToStr(array[i]);
		}
	}
	Sleep(500);
	Application->ProcessMessages();
	for(int i = 1; i < 15; i++)
	{
		for(int l = 1; l < 15; l++)
		{
			SG1->Cells[i][l] = "";
		}
	}
	for(int o = 1, i = 0; o < 15; o++, i++)
	{
		SG1->Cells[o][array[i]] = IntToStr(array[i]);
	}
}

void shellSort(TStringGrid* SG1, int *num, int size)
{
  int increment = 3;    // начальное приращение сортировки
  while (increment > 0)  // пока существует приращение
  {
	for (int i = 0; i < size; i++)  // для всех элементов массива
    {
      int j = i;          // сохраняем индекс и элемент
	  int temp = num[i];
      // просматриваем остальные элементы массива, отстоящие от j-ого
      // на величину приращения
      while ((j >= increment) && (num[j - increment] > temp))
      {  // пока отстоящий элемент больше текущего
        num[j] = num[j - increment]; // перемещаем его на текущую позицию
        j = j - increment;       // переходим к следующему отстоящему элементу
      }
	  num[j] = temp; // на выявленное место помещаем сохранённый элемент
	  Sleep(500);
	  Application->ProcessMessages();
	  for(int k = 1; k < 15; k++)
	  {
		for(int l = 1; l < 15; l++)
		{
		  SG1->Cells[k][l] = "";
		}
	  }
	  for(int o = 1, k = 0; o < 15; o++, k++)
	  {
		SG1->Cells[o][num[k]] = IntToStr(num[k]);
	  }
	}
	if (increment > 1)      // делим приращение на 2
      increment = increment / 2;
    else if (increment == 1)   // последний проход завершён,
      break;  // выходим из цикла
  }
}

void shakerSort(TStringGrid* SG1, int *mass, int count)
{
  int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
  int flag = 1;  // флаг наличия перемещений
  // Выполнение цикла пока левая граница не сомкнётся с правой
  // и пока в массиве имеются перемещения
  for(int k = 1; k < 15; k++)
  {
    for(int l = 1; l < 15; l++)
	{
	  SG1->Cells[k][l] = "";
	}
  }
  for(int o = 1, k = 0; o < 15; o++, k++)
  {
	SG1->Cells[o][mass[k]] = IntToStr(mass[k]);
  }
  while ((left < right) && flag > 0)
  {
	flag = 0;
    for (int i = left; i<right; i++)  //двигаемся слева направо
    {
      if (mass[i]>mass[i + 1]) // если следующий элемент меньше текущего,
	  {             // меняем их местами
        double t = mass[i];
        mass[i] = mass[i + 1];
        mass[i + 1] = t;
        flag = 1;      // перемещения в этом цикле были
      }
    }
    right--; // сдвигаем правую границу на предыдущий элемент
    for (int i = right; i>left; i--)  //двигаемся справа налево
    {
      if (mass[i - 1]>mass[i]) // если предыдущий элемент больше текущего,
      {            // меняем их местами
		int t = mass[i];
        mass[i] = mass[i - 1];
        mass[i - 1] = t;
        flag = 1;    // перемещения в этом цикле были
	  }
	}
	left++; // сдвигаем левую границу на следующий элемент
	Sleep(500);
	Application->ProcessMessages();
	for(int k = 1; k < 15; k++)
	{
	  for(int l = 1; l < 15; l++)
	  {
		SG1->Cells[k][l] = "";
	  }
	}
	for(int o = 1, k = 0; o < 15; o++, k++)
	{
	  SG1->Cells[o][mass[k]] = IntToStr(mass[k]);
	}
  }
}
