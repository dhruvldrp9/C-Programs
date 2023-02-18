#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct ar
{
    int n;
    int a[100];
};


void getdata(struct ar *l)
{
	int z;
    printf("\nYou can enter Maximum 100 Data.\nHow many number of data You Want to enter : ");
    scanf("%d",&z);
    l->n = z-1;
    
    printf("\nRandom Data : ");
	srand(time(0));
	int i = 0; 
	while(i < z)
    {
    	//scanf("%d",&l->a[i]);
		l->a[i] = rand()%100;
    	printf("%d ",l->a[i]);
        i++;
	}
}


int sortdata(struct ar *l)
{
	int min,temp,flag;
	int i=0;
	while(i<l->n)
	{
		min=i;
		flag=1;
		int j=i+1;
		while(j<=l->n)
		{
			if(l->a[min] > l->a[j])
			{
				min = j;
			}
			if (l->a[j-1] > l->a[j])
			{
				flag = 0;
			}
			j++;
		}
		if(flag == 1)
		{
			return 0;
		}
		temp = l->a[i];
		l->a[i] = l->a[min];
		l->a[min] = temp;
		i++;
	}
	return 0;
}

void printdata(struct ar *l)
{
	printf("\nSorted data : ");
	int i=0;
	while(i<=l->n)
	{
		printf(" %d",l->a[i]);
		i++;
	}
	printf("\n");
}

void BSearch(struct ar *l)
{
	int target;
	int count=0;
	printf("\nEnter Data You Want to Search : ");
	scanf("%d",&target);
	int low = 0;
	int high = l->n;

	printf("\nPath To Search : ");
	while(high >= low)
	{
		count++;
		int mid = (high+low)/2;
		if(l->a[mid] == target)
		{
			printf("%d\n",l->a[mid]);
			printf("\nTarget Found at Index %d.",mid+1);
			break;
		}
		else if(l->a[mid] > target)
		{
			printf("%d ->",l->a[mid]);
			high = mid-1;
		}
		else
		{
			printf("%d ->",l->a[mid]);
			low = mid+1;
		}
	}
	if(high<low)
	{
		printf(" Not Found\nData not Found.");
	}
	printf("\nThere would %d steps taken to find Target.",count);
}

void main()
{
	clock_t t;
	struct ar l;
	t=clock();
	getdata(&l);
    sortdata(&l);
	printdata(&l);
	BSearch(&l);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nBinary Search took %f seconds to execute \n", time_taken);
	printf("\n\n\n");
}
