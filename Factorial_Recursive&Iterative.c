#include<stdio.h>
#include<time.h>

unsigned long long int factorial_iterative(unsigned long long int n)
{
	unsigned long long int fact = 1;
	unsigned long long int i=1;
	while(i<=n)
	{
		fact = fact * i;
		i++;
	}
	return fact;
}

unsigned long long int factorial_recursive(unsigned long long int n)
{
	unsigned long long int fact;
	if(n==1 || n==0)
	{
		return 1;
	}
	else
	{
		fact = n * factorial_recursive(n-1);
	}
	return fact;
}

int main()
{
	unsigned long long int fact1,fact2;
	long int n;
    clock_t t;
    int num;
    do
	{
		printf("\nBy which method do you want to find factorial?");
		printf("\n1.Iterative Method.");
		printf("\n2.Recursive Method.");
		printf("\n3.Exit");
		printf("\nChoose any one : ");
		scanf("%d",&num);
		switch (num)
		{
		case 1:
			t = clock();
			first:
	        printf("\nTo find factorial enter number : ");
	        scanf("%ld",&n);
	        if (n < 0)
	        {
		        goto first;
	        }
			fact1 = factorial_iterative(n);
	        printf("\nFactorial of %llu is %llu with Iteraitve Method.",n,fact1);
            t = clock() - t;
			double time_taken = ((double)t)/CLOCKS_PER_SEC;
 
            printf("\n\nfun() took %f seconds to execute \n", time_taken);
    
			break;
		case 2:
		    t = clock();
			second:
	        printf("\nTo find factorial enter number : ");
	        scanf("%ld",&n);
	        if (n < 0)
	        {
		        goto second;
	        }
			fact2 = factorial_recursive(n);
	        printf("\nFactorial of %llu is %llu with Recursive Method.",n,fact2);
			t = clock() - t;
			time_taken = ((double)t)/CLOCKS_PER_SEC;
 
            printf("\n\nfun() took %f seconds to execute \n", time_taken);
    
			break;
		default:
			break;
		}
	} while (num != 3);
	



	return 0;
}
