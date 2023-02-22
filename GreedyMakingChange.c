#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void main()
{
    clock_t t;
    int x[5] = {1,4,5};
    int a[10];
    int value = 33;
    int k = 2;
    int j = 0;
    t = clock();
    while (value > 0 && k >= 0)
    {
        while(x[k] <= value)
        {
            a[j] = x[k];
            value = value - x[k];
            j++;
        }
        k--;
    }
    if(value > 0)
    {
        printf("\nNot Valid");
    }
    else
    {
        printf("\nValid.\nCoin Used : ");
        for (int i = 0; i < j; i++)
        {
            printf("%d ",a[i]);
        }
    }

    t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nGreedy Making Change Algorithm took %f seconds to execute \n", time_taken);
    
}