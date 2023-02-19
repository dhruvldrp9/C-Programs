#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define v 9
#define r 8

int vis[v];
int Graph[v][v] = {{0, 1, 1, 0, 0, 0, 0, 0, 0},
                   {1, 0, 0, 1, 1, 0, 0, 0, 0},
                   {1, 0, 0, 0, 0, 0, 1, 1, 0},
                   {0, 1, 0, 0, 0, 0, 0, 0, 0},
                   {0, 1, 0, 0, 0, 1, 0, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0, 0, 1},
                   {0, 0, 1, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0, 0}};

void DFS(int a)
{
    vis[a]=1;
    printf(" -> %d",a);
    for(int b=0;b<v;b++)
    {
        if(vis[b]==0 && Graph[a][b]==1)
        {
            DFS(b);
        }
    }
}

void main()
{
    for(int i=0;i<v;i++)
    {
        vis[i]=0;
    }
    DFS(r);
}