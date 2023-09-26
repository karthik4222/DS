#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void insert(int x)
{
    struct node*temp=head;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if(head==NULL || x<temp->data)
    {
        newnode->next=head;
        head=newnode;
    }
    else{
        while(temp->next!=NULL && temp->next->data<x)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void print()
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void removed()
{
    struct node*temp= head;
    head=temp->next;
    printf("Element is removed updated list is:\n");
     print();
}
int top()
{
    return head->data;
}


int main()
{
    int n;
    printf("Enter no.of elements you want to insert:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        insert(x);
    }
    print();
    removed();
    removed();
    
}