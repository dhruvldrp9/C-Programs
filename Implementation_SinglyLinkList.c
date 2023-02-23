#include<stdio.h>
#include<stdlib.h>



struct node 
{
    int data;
    struct node *next;
};

struct sinL
{
    struct node *head;
};


void init(struct sinL *l)
{
    l->head=NULL;
}

void addnode(struct sinL *l, int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    
    if (temp == NULL)
    {
        printf("No memory get.");
    }
    else
    {
        if (l->head == NULL)
        {
            l->head = temp;
            temp->data = x;
            temp->next = NULL;
        }
        else
        {
            struct node *t = l->head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
            temp->data = x;
            temp->next = NULL;
        }
        
    }
}

void searchnode(struct sinL *l, int x)
{
    struct node *temp = l->head;
    while(temp->data != x && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->data == x)
    {
        printf("\nYour Data is found at address %p.",temp);   
    }
    else
    {
        printf("\nData Not Found.");
    }
    
    
}


void displaynode(struct sinL *l)
{
    struct node *temp = l->head;
    while(temp->next != NULL)
    {
        printf("\n %d ",temp->data);
        temp = temp->next;
    }
    printf("\n %d ",temp->data);
}





int main()
{
    struct sinL l;
    int x;
    int n;

    init(&l);


    do
    {
        printf("\n1.Add Data");
        printf("\n2.Search Data");
        printf("\n3.Display Data");
        printf("\n4.exit");
        printf("\nChoose any one : ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("\nEnter data you want to enter : ");
            scanf("%d",&x);
            addnode(&l, x);
            break;
        case 2:
            printf("Enter data you want to Search : ");
            scanf("%d",&x);
            searchnode(&l, x);
            break;
        case 3:
            displaynode(&l);
            break;

        
        default:
            break;
        }
    } while (n != 4);
    



    
}