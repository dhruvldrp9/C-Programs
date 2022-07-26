#include<stdio.h>
#include<stdlib.h>

struct ar
{
    int n;
    int a[10];
};


void getdata(struct ar *l)
{
	int z;
    printf("\nYou can enter Maximum 10 Data.\nHow many number of data You Want to enter?");
    scanf("%d",&z);
    l->n = z-1;
    
    //printf("\nEnter Data : ");
	for (int i = 0; i < z; i++)
    {
    	//scanf("%d",&l->a[i]);
		l->a[i] = rand()%50;
    	printf(" ");
	}
}

int sortdata(struct ar *l)
{
	int min,temp,flag;
	for(int i=0;i<l->n;i++)
	{
		min=i;
		flag=1;
		for(int j=i+1;j<=l->n;j++)
		{
			if(l->a[min] > l->a[j])
			{
				min = j;flag=0;
			}
		}
		if(flag == 1)
		{
			return 0;
		}
		temp = l->a[i];
		l->a[i] = l->a[min];
		l->a[min] = temp;
	}
	return 0;
}

void printdata(struct ar *l)
{
	printf("\nSorted data : ");
	for(int i=0;i<=l->n;i++)
	{
		printf(" %d",l->a[i]);
	}
	printf("\n");
}


int main()
{
    struct ar l;
    getdata(&l);
    sortdata(&l);
	printdata(&l);
	return 0;
	

}
