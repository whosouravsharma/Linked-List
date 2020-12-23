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
void create_node(node *last)
{
    if(!last->info)
    {
        printf("Enter the info ");
        scanf("%u",&last->info);
        last->link=last;
    }
    else
    {
        printf("The memory already contains info\n");
    }

}
// display nodes
node *display(node*last)
{
    node* first=last->link;
    if(!last->info)
    {
        printf("The list is already empty\n");
    }
    else
    {
        printf("Your existing info are:\n");

        do
        {
            printf("%u ",first->info);
            first=first->link;
        }
        while(first->link!=last);
        printf("\n");
    }
}
// add at the begining
node* add_beg(node * last)
{
    if(last)
    {
        node*new=(node*)malloc(sizeof(node));
        printf("Enter the info:\n");
        scanf("%u",&new->info);
        new->link=last->link;
        last->link=new;
    }
    else
    {
        printf("THe node is empty\n");
        // create_node(last);
    }
}
// add in the mid
node* add_mid(node* last)
{
    int num;
    printf("Enter the data you want to add after\n");
    scanf("%d",&num);
    node*temp=last->link;
    while(temp->info!=num)
    {
        temp=temp->link;
    }
    printf("Enter the info you want to add:\n");
    node*new=(node*)malloc(sizeof(node));
    scanf("%u",&new->info);
    new->link=temp->link;
    temp->link=new;
    return last;
}
// add in the end
node* add_end(node *last)
{
    node*new=(node*)malloc(sizeof(node));
    printf("Enter the info you want to enter\n");
    scanf("%u",&new->info);
    new->link=last->link; 
    last->link=new; 
    last=new; 

    return last; 
}
// delete at the beggining
void del_beg(node **last)
{
    if(*last)
    {
        node *temp=*last;
        *last=temp->link;
        free(temp);
    }
    else
    {
        printf("Some error occured(Empty maybe)\n");
    }

}
// delete at the middle
void del_mid(node*last)
{
    if(!last->info)
    printf("list is empty");
    else
    {
        int num;
        printf("Enter the data you want to delete: ");
        scanf("%d",&num);
        node*p=last;
        node*q=last->link;

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
void del_end(node*last)
{
    if(!last->info)
    printf("Some error occured(Empty maybe)");
    else
    {
        node*p=last;
        node*q=last->link;

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
// reverse singly linked list
node* reverse(node*last)
{
    node*p=last;
    node*q=NULL;
    node*r;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->link;
        q->link=r;
    }
    last=q;
}



//  main 
int main()
{
    node *last;
    last=(node*)malloc(sizeof(node));
    int ch1,ch3;
    char ch2;
    int flag=1;

    while(flag==1)
    {
        printf("\nCIRCULAR LINKED LIST\n");
        printf("Enter your choice: \n");
        printf("1. Create a node\n");
        printf("2. Display nodes\n");
        printf("3. Add a node\n");
        printf("4. Delete a node\n");
        printf("5. Reverse linked list\n");
        scanf("%d",&ch1);

        if(ch1==1)
        {
            printf("\n");
            create_node(last);  
        }

        else if (ch1==2)
        {
            printf("\n");
            display(last);
        }

        else if (ch1==3)
        {
            if(!last->info)
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
                    add_beg(last);
                else if(ch3==2)
                    add_mid(last);
                else if(ch3==3)
                    add_end(last); 
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
                    del_beg(&last);
                }
                else if(ch3==2)
                {
                    del_mid(last);
                }
                else if(ch3==3)
                {
                    del_end(last);
                }
        }
        else if(ch1==5)
        {
            reverse(last);
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