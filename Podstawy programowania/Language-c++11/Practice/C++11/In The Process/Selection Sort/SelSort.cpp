#include <iostream>

void selectionSort(int arr[], int start, int size);
void printArr(int arr[], int size);

int main()
{
  const int size {7 };
  int arr[size] {3, 7, -1, 12, -5, 7, 10};
  selectionSort(arr, 0, size);
  return 0;
}

void selectionSort(int arr[], int start, int size)
{
  printArr(arr, size)

  for (int i = start; i < size; i++)
  {
    int min_pos { i };
    for (int x = i; x < size; x++)
    {
      if (arr[x] < arr[min_pos])
      {
        min_pos = x;
      }
    }
    int temp { arr[i] };
    arr[i] = arr[min_pos];
    arr[min_pos] = temp;
    printArr(arr, size)
  }

  printArr(arr, size)
}

void printArr(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
