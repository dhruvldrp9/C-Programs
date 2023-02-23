#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int BinarySearch(int **arr, int n, int target, int q[])
// {
//     int left = 0;
//     int right = n - 1;
//     int mid;
//     while (right >= left)
//     {
//         mid = left + (right - left) / 2;
//         if (arr[mid] == target)
//         {
//             return mid;
//         }
//         if (target < arr[mid])
//         {
//             right = mid - 1;
//         }
//         else
//         {
//             left = mid + 1;
//         }
//     }
//     return -1;
// }

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
    // return x>y?x:y;
}

int knapsack(int W, int wt[], int pro[], int n)
{
    int w, i;
    int tab[n + 1][W + 1];
    // printf("%d %d",n,W);
    // for(int e=0;e<=2;e++)
    //{
    //   printf("\n%d %d",wt[e],pro[e]);
    //}
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                tab[i][w] = 0;
                printf("%d\t", tab[i][w]);
            }
            else if (w >= wt[i - 1])
            {
                // tab[i][w] = max(tab[i-1][w], tab[i-1][w-wt[i-1]] + pro[i-1]);
                // int temp = w - wt[i-1];
                if (tab[i - 1][w] >= (tab[i - 1][w - wt[i - 1]] + pro[i - 1]))
                {
                    tab[i][w] = tab[i - 1][w];
                }
                else
                {
                    tab[i][w] = tab[i - 1][w - wt[i - 1]] + pro[i - 1];
                }
                printf("%d\t", tab[i][w]);
            }
            else
            {
                tab[i][w] = tab[i - 1][w];
                printf("%d\t", tab[i][w]);
            }
        }
        printf("\n");
    }
    printf("\nProfit is %d", tab[n][W]);
    printf("\nHere Objects are : \n");
    printf("\nObject\tWeight\tProfit");
    int profit = tab[n][W];
    int q[n];
    int r = 0;
    for (i = n; i >= 0; i--)
    {
        int left = 0;
        int right = W;
        int mid;
        int count = 0;
        while (right >= left)
        {
            mid = left + (right - left) / 2;
            if (tab[i][mid] == profit)
            {
                q[r] = i;
                count = 1;
                break;
            }
            else if (profit < tab[i][mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (count == 0)//tab[i][mid] != profit)
        {
            r++;
            profit = profit - pro[i];
        }        
    }
    for (int a = 0; a <= r; a++)
    {
        printf("\n%d\t%d\t%d", q[a], wt[q[a] - 1], pro[q[a] - 1]);
    }
    // for(i=n;i>=0;i--)
    // {
    //     if(tab[n][W] != tab[i-1][W])
    //     {
    //         profit = profit - pro[i-1];
    //         for()
    //     }
    // }

    // printf("\n%d", profit);
}

int main()
{
    int W = 8;
    int wt[3] = {2, 4, 5};
    int pro[3] = {3, 5, 8};
    int n = sizeof(wt) / sizeof(wt[0]);
    knapsack(W, wt, pro, n);
}
