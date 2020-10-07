#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
    int co;
    int ex;
    struct node* link;
}node;
void poly1(node *start,int co,int ex)
{
    node*temp,*ptr;
    if(!start->co || start->ex)
    {
        start->co=co;
        start->ex=ex;
        start->link=NULL;  
    }
    else
    {
        temp=start;
        while(temp->link!=NULL && temp->link->ex>ex)
        {
            temp=temp->link;
        }
        node *ptr=(node*)malloc(sizeof(node));
        ptr->co=co;
        ptr->ex=ex;
        ptr->link=NULL;
        temp->link=ptr;
    }   
}
void poly2(node *start,int co,int ex)
{
    node*temp,*ptr;
    if(!start->co || start->ex)
    {
        start->co=co;
        start->ex=ex;
        start->link=NULL;  
    }
    else
    {
        temp=start;
        while(temp->link!=NULL && temp->link->ex>ex)
        {
            temp=temp->link;
        }
        node *ptr=(node*)malloc(sizeof(node));
        ptr->co=co;
        ptr->ex=ex;
        ptr->link=NULL;
        temp->link=ptr;
    }   
}
void display(node * start, int ex, int co)
{
    do
    {
        printf("%u ",start->co);
        printf("%u ",start->ex);
        start=start->link;
    }while(start!=NULL);
    printf("\n");
}
void add(node *start1,node *start2)
{
    node *start3;
    start3=(node*)malloc(sizeof(node));
}
int main()
{
    node *start1;
    int co1,ex1;
    start1=(node*)malloc(sizeof(node));
    printf("Polynomial-1: \n");
    scanf("%d%d",&co1,&ex1);
    char ch;
    int flag1=1;
    
    while(flag1==1)
    {
        printf("Do you want to add more?(Y/N)\n");
        scanf(" %c",&ch);
        ch=tolower(ch);

        if(ch=='n')
        flag1=0;
        else if(ch=='y')
        {
            printf("Polynomial-1: \n");
            scanf("%d%d",&co1,&ex1);
            poly1(start1,co1,ex1);
            flag1=1;
        }
    }

    node *start2;
    int co2,ex2;
    start2=(node*)malloc(sizeof(node));
    printf("Polynomial-2: \n");
    scanf("%d%d",&co2,&ex2);
    int flag2=1;
    
    while(flag2==1)
    {
        printf("Do you want to add more?(Y/N)\n");
        scanf(" %c",&ch);
        ch=tolower(ch);

        if(ch=='n')
        flag2=0;
        else if(ch=='y')
        {
            printf("Polynomial-2: \n");
            scanf("%d%d",&co2,&ex2);
            poly2(start2,co2,ex2);
            flag2=1;
        }
    }
    add(start1,start2);
    display(start1,co1,ex1);
    display(start2,co2,ex2);
    
}