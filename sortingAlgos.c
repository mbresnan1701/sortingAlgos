#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* mergeSort(int* arr, int arrLen);

int main(int argc, char **argv)
{
  int arr[9] = {11, 22, 41, 5, 16, 71, 18, 9, 1};
  // int arr[5] = {3, 2, 1, 16, 2};
  int size = sizeof(arr) / sizeof(int);
  int* merged = mergeSort(arr, size);
  printf("Merged list is: \n");
  for(int i = 0; i < size; i++)
  {
    printf("%i ", merged[i]);
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