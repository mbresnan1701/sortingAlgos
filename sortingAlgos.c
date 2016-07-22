#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* mergeSort(int* arr, int arrLen);
void bubbleSort(int* arr, int arrLen);
void selectionSort(int* arr, int arrLen);
void insertionSort(int* arr, int arrLen);

void shiftElementsRight(int* arr, int arrLen,  int start, int stop);
void shiftElementsLeft(int* arr, int arrLen,  int start, int stop);
void relocateElement(int* arr, int arrLen, int targetIndex, int currentIndex);

int main(int argc, char **argv)
{
  // int arr[10] = {11, 22, 41, 5, 16, 71, 18, 9, 1, 66};
  int arr[4] = {69, 16, 17, 66};
  int size = sizeof(arr) / sizeof(int);
  // int* merged = selectionSort(arr, size);
  // int* sorted = selectionSort(arr, size);
  insertionSort(arr, size);
  printf("Insertion list is: \n");
  for(int i = 0; i < size; i++)
  {
    printf("%i ", arr[i]);
  }
  return 0;
}

int* mergeSort(int* arr, int arrLen)
{
  if(arrLen <= 1)
  {
    return arr;
  }
  else
  {
    int* left;
    int* right;
    int* merged;
    int leftSize = arrLen / 2;
    int rightSize = arrLen - leftSize;

    left = malloc((sizeof(int) * leftSize));
    right = malloc((sizeof(int) * rightSize));
    merged = malloc((sizeof(int) * arrLen));

    for(int i = 0; i < leftSize; i++)
    {
      left[i] = arr[i];
    }

    for(int j = arrLen / 2; j < arrLen; j++)
    {
      right[j - (arrLen / 2)] = arr[j];
    }

    left = mergeSort(left, leftSize);
    right = mergeSort(right, rightSize);

    int lPos = 0;
    int rPos = 0;
    int placed = 0;

    while(placed < arrLen)
    {
      if(lPos == leftSize)
      {
        merged[placed++] = right[rPos++];
      }
      else if(rPos == rightSize)
      {
        merged[placed++] = left[lPos++];
      }
      else
      {
        if(left[lPos] < right[rPos])
        {
          merged[placed++] = left[lPos++];
        }
        else if(left[lPos] > right[rPos])
        {
          merged[placed++] = right[rPos++];
        }
        else
        {
          merged[placed++] = right[rPos++];
        }
      }
    }

    free(left);
    free(right);
    return merged;
  }
}

void bubbleSort(int* arr, int arrLen)
{
  int changeMade = 0;
  while(1)
  {
    for(int i = 0; i < arrLen - 1; i++)
    {
      if(arr[i] > arr[i + 1])
      {
        arr[i] = arr[i] ^ arr[i + 1];
        arr[i + 1] = arr[i] ^ arr[i + 1];
        arr[i] = arr[i] ^ arr[i + 1];
        changeMade = 1;
      }
    }
    if(changeMade == 0)
    {
      break;
    }
    else
    {
      changeMade = 0;
    }
  }
}

void selectionSort(int* arr, int arrLen)
{
  int placed = 0;
  int minIndex;
  while(placed < arrLen - 1)
  {

    minIndex = placed;

    for(int i = placed; i < arrLen; i++)
    {
      if(arr[i] < arr[minIndex])
      {
        minIndex = i;
      }
    }

    if(minIndex != placed)
    {
      relocateElement(arr, arrLen, placed, minIndex);
    }

    placed++;
  }
}

void insertionSort(int* arr, int arrLen)
{
  int currentIndex = 0;
  for(int i = 1; i < arrLen; i++)
  {
    for(int j = 0; j <= currentIndex; j++)
    {
      if(arr[j] >= arr[i])
      {
        relocateElement(arr, arrLen, j, i);
      }
    }
    currentIndex++;
  }
}

void relocateElement(int* arr, int arrLen, int targetIndex, int currentIndex)
{
  if(targetIndex != currentIndex)
  {
    int temp = arr[currentIndex];
    if(targetIndex < currentIndex)
    {
      shiftElementsRight(arr, arrLen, currentIndex, targetIndex);
      arr[targetIndex] = temp;
    }
    else if(targetIndex > currentIndex)
    {
      shiftElementsLeft(arr, arrLen, currentIndex, targetIndex);
      arr[targetIndex] = temp;
    }
  }

}

void shiftElementsRight(int* arr, int arrLen, int start, int stop)
{
  for(int i = start; i > stop; i--)
  {
    arr[i] = arr[i - 1];
  }
}

void shiftElementsLeft(int* arr, int arrLen, int start, int stop)
{
  for(int i = start; i < stop; i++)
  {
    arr[i] = arr[i + 1];
  }
}

// [3, 2, 1, 4, 6]
// [3, 6, 2, 1, 4]

// [3, 2, 1, 4, 6]
// [2, 1, 4, 3, 6]
  // int arr[5] = {69, 16, 17};
  //              {16, 69, 17}








