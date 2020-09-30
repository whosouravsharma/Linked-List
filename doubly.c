#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

// structure for singly nexted list
typedef struct node
{
    int info;
    struct node *prev;
    struct node *next;
}node;

//  create a node
void create_node(node *start)
{
    if(!start->info)
    {
        printf("Enter the info ");
        scanf("%u",&start->info);
        start->prev=NULL;
        start->next=NULL;
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
        printf("Your existing info(s) are:\n");
        node*temp=start;
        do
        {
            printf("%u ",temp->info);
            temp=temp->next;
        }
        while(temp!=NULL);
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
        temp->next=*start;
        temp->prev=NULL;
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
        temp=temp->next;
    }
    printf("Enter the info you want to add:\n");
    node*new=(node*)malloc(sizeof(node));
    scanf("%u",&new->info);
    new->next=temp->next;
    new->prev=temp;
    temp->next->prev=new;
    temp->next=new;
}

// add in the end
void add_end(node *start)
{
    node*temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node*new=(node*)malloc(sizeof(node));
    printf("Enter the info you want to enter\n");
    scanf("%u",&new->info);
    temp->next=new;
    new->prev=temp;
    new->next=NULL;
}
// delete at the beggining
void del_beg(node **start)
{
    if(*start)
    {
        node *temp=*start;
        temp->next->prev=NULL;
        *start=temp->next;
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
        node*q=start->next;

        while(q->info!=num)
        {
            p=p->next;
            q=q->next;
        }
        node *temp=q;
        p->next=q->next;
        q->next->prev=p;
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
        node*q=start->next;

        while(q->next!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        node *temp=q;
        p->next=NULL;
        free(temp);
    }
    
}
// reverse singly nexted list
void reverse(node**start)
{
    node*p=*start;
    node*q=NULL;
    node*r;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    *start=q;
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
        printf("\nDOUBLY nextED LIST\n");
        printf("Enter your choice: \n");
        printf("1. Create a node\n");
        printf("2. Display nodes\n");
        printf("3. Add a node\n");
        printf("4. Delete a node\n");
        printf("5. Reverse nexted list\n");
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
        else if(ch1==5)
        {
            reverse(&start);
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