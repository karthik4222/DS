#include<stdio.h>
#define v 4
void AddEdge(int matrix[][v],int i,int j)
{
    matrix[i][j]=1;
    matrix[j][i]=1;
}
void printMatrix(int matrix[][v])
{
    for(int i=0;i<v;i++)
    {
        printf("Edge %d:",i);
        for(int j=0;j<v;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int matrix[v][v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            matrix[i][j]=0;
        }
    }
    AddEdge(matrix,0,1);
    AddEdge(matrix,0,3);
    AddEdge(matrix,1,2);
    AddEdge(matrix,2,3);
    printMatrix(matrix);
}