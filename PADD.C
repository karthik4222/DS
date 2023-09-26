#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node* next;
};

struct node* insert(struct node*head,int exp,int coeff)
{
    struct node* temp=head;
    struct node* temp1=(struct node*)malloc(sizeof(struct node));
    temp1->coeff=coeff;
    temp1->exp=exp;
    if(head==NULL||head->exp<exp)
    {
        temp1->next=head;
        head=temp1;
    }
    else{
        while(temp->next!=NULL && temp->next->exp>=exp)
        {
            temp=temp->next;
        }
        temp1->next=temp->next;
        temp->next=temp1;
    }
    return head;
}

struct node* create(struct node* head)
{
    int n;
    printf("Enter no.of terms: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int exp,coeff;
        printf("Enter coefficient and exponent: ");
        scanf("%d%d",&coeff,&exp);
        head=insert(head,exp,coeff);
    }
    return head;
}

void display(struct node* head)
{
    struct node*temp= head;
    while(temp!=NULL)
    {
        printf("%dx^%d + ",temp->coeff,temp->exp);
        temp=temp->next;
    }

}
struct node* add(struct node* head1,struct node*head2)
{
    struct node* temp=NULL;
    while(head1!=NULL &&  head2!=NULL)
    {
        if(head1->exp>head2->exp)
        {
            temp=insert(temp,head1->exp,head1->coeff);
            head1=head1->next;
        }
        else if(head1->exp<head2->exp)
        {
            temp=insert(temp,head2->exp,head2->coeff);
            head2=head2->next;
        }
        else
        {
            temp=insert(temp,head1->exp,head2->coeff+head1->coeff);
            head1=head1->next;
            head2=head2->next;
        }

    }
    return temp;
}
int main()
{
    struct node* pol1=NULL;
    pol1=create(pol1);
    struct node*pol2=NULL;
    pol2=create(pol2);
    printf("Polynomial 1:\n");
    display(pol1);
    printf("\nPolynomial 2:\n");
    display(pol2);
    struct node* pol3=add(pol1,pol2);
    printf("\nResultant polynomial:\n");
    display(pol3);
}