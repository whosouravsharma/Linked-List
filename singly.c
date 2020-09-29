#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

// structure for singly linked list
typedef struct node
{
    int info;
    struct node *link;
}node;

//  create a node
void create_node(node *start)
{
    if(!start->info)
    {
        printf("Enter the info ");
        scanf("%u",&start->info);
        start->link=NULL;
    }
    else
    {
        printf("The memory already contains info\n");
    }
    
}
// display nodes
void display(node*start)
{
    if(!start->info)
    {
        printf("The list is already empty\n");
    }
    else
    {
        printf("Your existing info are:\n");
        do
        {
        printf("%u ",start->info);
        start=start->link;
        }
        while(start!=NULL);
        printf("\n");
    }
    
    
}
// add at the begining
void add_beg(node ** start)
{
    if(*start)
    {
        node*temp=(node*)malloc(sizeof(node));
        printf("Enter the info:\n");
        scanf("%u",&temp->info);
        temp->link=*start;
        *start=temp;
    }
    else
    {
        printf("Some error has occured (Maybe empty)\n");
    }
}
// add in the mid
void add_mid(node* first)
{
    int num;
    printf("Enter the data you want to add after\n");
    scanf("%d",&num);
    node*temp=first;
    while(temp->info!=num)
    {
        temp=temp->link;
    }
    printf("Enter the info you want to add:\n");
    node*new=(node*)malloc(sizeof(node));
    scanf("%u",&new->info);
    new->link=temp->link;
    temp->link=new;
}
// add in the end
void add_end(node *start)
{
    while(start->link!=NULL)
    {
        start=start->link;
    }
    node*new=(node*)malloc(sizeof(node));
    printf("Enter the info you want to enter\n");
    scanf("%u",&new->info);
    start->link=new;
    new->link=NULL;
}
// delete at the beggining
void del_beg(node **start)
{
    if(*start)
    {
        node *temp=*start;
        *start=temp->link;
        free(temp);
    }
    else
    {
        printf("Some error occured(Empty maybe)\n");
    }
    
}
// delete at the middle
void del_mid(node*start)
{
    if(!start->info)
    printf("list is empty");
    else
    {
        int num;
        printf("Enter the data you want to delete: ");
        scanf("%d",&num);
        node*p=start;
        node*q=start->link;

        while(q->info!=num)
        {
            p=p->link;
            q=q->link;
        }
        node *temp=q;
        p->link=q->link;
        free(temp);
    }
    
}
// delete at the end
void del_end(node*start)
{
    if(!start->info)
    printf("Some error occured(Empty maybe)");
    else
    {
        node*p=start;
        node*q=start->link;

        while(q->link!=NULL)
        {
            p=p->link;
            q=q->link;
        }
        node *temp=q;
        p->link=NULL;
        free(temp);
    }
    
}



//  main 
int main()
{
    node *start;
    start=(node*)malloc(sizeof(node));
    int ch1,ch3;
    char ch2;
    int flag=1;
    
    while(flag==1)
    {
        printf("\n");
        printf("Enter your choice: \n");
        printf("1. Create a node\n");
        printf("2. Display nodes\n");
        printf("3. Add a node\n");
        printf("4. Delete a node\n");
        scanf("%d",&ch1);

        if(ch1==1)
        {
            printf("\n");
            create_node(start);  
        }

        else if (ch1==2)
        {
            printf("\n");
            display(start);
        }

        else if (ch1==3)
        {
            if(!start->info)
            printf("\n******Please create a node first!******\n");
            else 
            {
                printf("\n");
                printf("Enter the location you want to add info\n");
                printf("1. Beggining\n");
                printf("2. (Middle) After certain info\n");
                printf("3. At the end\n\n");
                scanf("%d",&ch3);

                if(ch3==1)
                    add_beg(&start);
                else if(ch3==2)
                    add_mid(start);
                else if(ch3==3)
                    add_end(start); 
            }

        }
        else if(ch1==4)
        {
            printf("\n");
                printf("Enter the location you want to delete info\n");
                printf("1. Beggining\n");
                printf("2. Certain node\n");
                printf("3. At the end\n\n");
                scanf("%d",&ch3);
                if(ch3==1)
                {
                    del_beg(&start);
                }
                else if(ch3==2)
                {
                    del_mid(start);
                }
                else if(ch3==3)
                {
                    del_end(start);
                }
        }
        printf("Do you wish to continue?(Y/N)\n");
        scanf(" %c",&ch2);
        ch2=toupper(ch2);
        if(ch2=='N')
        flag=0;
        else
        flag=1;
        
    }
    return 0;
}
