//Implement the code for MST using Prims algorithm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define v 5
#define r 2

int father[v] = {-1,-1,-1,-1,-1};
int prMST[v] = {0,0,0,0,0};
int cost[v] = {0,0,0,0,0};

int graph[v][v] = {{0,3,2,1,0},
                   {3,0,4,0,7},
                   {2,4,0,8,5},
                   {1,0,8,0,2},
                   {0,7,5,2,0}};

void Prim(int a)
{
    prMST[a] = 1;
    int temp;
    for(int b=0;b<v-1;b++)
    {
    int min = 9999;
    for (int i = 0; i < v; i++)
    {
        if (prMST[i] == 1)
        {
            for (int j = 0; j < v; j++)
            {
                if (prMST[j] == 0 && graph[i][j] != 0 && graph[i][j] < min)
                {
                    min = graph[i][j];
                    father[j] = i;
                    cost[j] = min;
                    temp = j;
                }
            }
        }
        
    }
    prMST[temp] = 1;
    }
    printf("Edge\tWeight\n");
    for (int i = 0; i < v; i++)
    {
        if (father[i] != -1)
        {
            printf("%d-%d\t%d\n",father[i],i,cost[i]);
        }
    }
    int sum = 0;
    for (int i = 0; i < v; i++)
    {
        sum += cost[i];
    }
    
    printf("Total Weight = %d",sum);   
}
int main()
{
    Prim(r);
}