#include<stdio.h>
#define max 10
int stack[max],topa=-1,topb=max;
void push_a(int x)
{
    if(topa==topb-1)
    {
        printf("Stack is full.\n");
    }
    else{
        topa++;
        stack[topa]=x;
    }
}
void push_b(int x)
{
    if(topb==topa+1)
    {
        printf("Stack B is full.\n");
    }
    else
    {
        topb--;
        stack[topb]=x;
    }
}
void pop_a()
{
    if(topa==-1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
    printf("%d is popped from stack A",stack[topa]);
    topa--;}
}
void pop_b()
{
    if(topb==max-1)
    printf("Stack B is empty.\n");
    else{
        printf("%d is popped from stack B",stack[topb]);
        topb++;
    }

}
void printa()
{
    printf("Elements of Stack A are: ");
    for(int i=topa;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
}
void printb()
{
    printf("Elements of Stack B are:");
    for(int i=topb;i<max;i++)
    printf("%d",stack[i]);

}
int main()
{
   int x;
   do{
    printf("\n1.insert in stack a\n2.insert in stack b\n3.pop stack a\n4.pop stack b\n5.print stack a\n6.print stack b\n7.exit\n");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
        {
            printf("Enter a number to insert:");
            int y;
            scanf("%d",&y);
            push_a(y);
            break;
        }
        case 2:
        {
            printf("Enter a number to insert:");
            int y;
            scanf("%d",&y);
            push_b(y);
            break;
        }
        case 3:
        {
            pop_a();
            break;
        }
        case 4:
        {
            pop_b();
            break;
        }
        case 5:
        {
            printa();
            break;
        }
        case 6:
        {
            printb();break;
        }
        case 7:
        {
            printf("Exit");break;
        }
        default:
        printf("Invalid choice.");
    }
   }while(x!=7);
}