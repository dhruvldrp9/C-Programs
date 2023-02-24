#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int mergesort(int x[],int temp[],int lb,int ub)
{
	if(lb>=ub)
	{
		return -1;
	}
	int mid = (lb+ub)/2;
	mergesort(x,temp,lb,mid);
	mergesort(x,temp,mid+1,ub);
	merge(x,temp,lb,ub,mid);
}

int merge(int x[],int temp[],int lb,int ub,int mid)
{
	int i=lb;
	int j=mid+1;
	int k=lb;
	while(i<=mid && j<=ub)
	{
		if(x[i]<=x[j])
		{
			temp[k] = x[i];
			i++;
		}
		else if(x[i]>x[j])
		{
			temp[k] = x[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		temp[k]=x[i];
		i++;k++;
	}
	while(j<=ub)
	{
		temp[k]=x[j];
		j++;k++;
	}
	int u=lb;
	while(u<=ub)
	{
		x[u] = temp[u];
		u++;
	}
}

int getdata(int x[])
{
	int n;
	printf("\nHow many elements do you want to enter : ");
	scanf("%d",&n);
	int ub = n-1;
	printf("\nRandom Data : ");
	srand(time(0));
	for(int i=0;i<=ub;i++)
	{
		x[i] = rand()%100;
    	printf("%d ",x[i]);
	}
	printf("\n");
	return ub;

	

}



void main()
{
	clock_t t;
	int lb = 0;
	int ub;
	int temp[10];
	int x[10];
	t = clock();
	ub = getdata(x);
	mergesort(x,temp,lb,ub);
	int w = lb;
	printf("\nSorted Data : ");
	while(w<=ub)
	{
		printf("%d ",x[w]);
		w++;
	}

	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nMerge Sort took %f seconds to execute \n", time_taken);
}
