#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearArrangeCoins(int n)
{
  clock_t start, stop;
  start = clock ();

  if(n > 2147483647 || n < 0)
    return -1;

  if(n == 1)
    return 1;
  
  int row = 0, count = 0, max = 0;

    for(int i = 0; i<n; i++)
    {
      row = 0;

        for(int k = 0; k<i+1; k++)
        {
          row++;

          if(row > max)
            max = row;

          if(count == n-1)
          {
            stop = clock();
            printf("\nSimple search required %.4f miliseconds\n", (float)(stop - start)/1000);
            printf("Row(k): %d\n", max);
            return max;
          }
          count++;
        }
    }

  return 0;
}

/////////////////////////////////////////

int arrangeCoins(int n)
{
  clock_t start, stop;
  start = clock ();

  long left = 0, right = n;
  long k, temp;

  while (left <= right) 
  {
    k = left + (right - left) / 2;
    temp = k * (k + 1) / 2;

    if (temp == n)
    {
      stop = clock();
      printf("\nBinary search required %.4f miliseconds\n", (float)(stop - start)/1000);
      printf("Row(k): %ld\n", k);
      return (int)k;
    }

    if (n < temp) 
      right = k - 1;
    else 
      left = k + 1;
    
  }

  stop = clock();
  printf("\nBinary search required %.4f miliseconds\n", (float)(stop - start)/1000);
  printf("Row(k): %ld\n", k);
  return (int)right;
}


///////////////////////////////////////
int main()
{
  int n = 2000000000;
  //scanf("%d\n", &n);
  printf("%d\n", n);

  arrangeCoins(n);
  linearArrangeCoins(n);

  return 0;
}