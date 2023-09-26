#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int expo;
    struct node* next;
};

struct node* insert(struct node* head,int y,int x)
{
    struct node* temp=head;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=y;
    newnode->expo=x;
    if(head==NULL || x>head->expo)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        int flag=0;
        while(temp->next!=NULL && temp->next->expo>=x)
        {
            
            temp=temp->next;
            
        
        
        }
        
        if(temp->expo==x)
        {
            temp->coeff+=y;
        }
        else{
        newnode->next=temp->next;
        temp->next=newnode;}
    }
    return head;
}

struct node* create(struct node* head)
{
    
    int n;
    printf("Enter no.of terms:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        printf("Enter coefficient and exponent: ");
        scanf("%d%d",&y,&x);
        head=insert(head,y,x);
    }
    return head;
}

struct node* multiply(struct node* head1,struct node* head2)
{
    struct node*temp=NULL;
    struct node* travel=head2;
    while(head1!=NULL)
    {
        travel=head2;
        while(travel!=NULL)
        {
            temp=insert(temp,travel->coeff*head1->coeff,head1->expo+travel->expo);
            travel=travel->next;
        }
        head1=head1->next;
    }
    return temp;
}
void display(struct node* head)
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%dx^%d",temp->coeff,temp->expo);
        if(temp->next!=NULL)
        printf(" + ");
        else
        printf("\n");
        temp=temp->next;
    }
}
int main()
{
    struct node* pol1=NULL;
    struct node* pol2=NULL;
    struct node* pol3=NULL;
    pol1=create(pol1);
    display(pol1);
    pol2=create(pol2);
    display(pol2);
    pol3=multiply(pol1,pol2);
    display(pol3);
}