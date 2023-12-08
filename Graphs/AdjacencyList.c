#include<stdio.h>
#include<stdlib.h>

struct node
{
    int vertice;
    struct node* next;
};
struct graph
{
  int numvertices;
  struct node** adjList;
};
struct graph* create_graph(int numvertices)
{
    struct graph* temp=(struct graph*)malloc(sizeof(struct graph));
    temp->numvertices=numvertices;
    temp->adjList=malloc(numvertices*sizeof(struct node));
    for(int i=0;i<numvertices;i++)
    {
        temp->adjList[i]=NULL;
    }
    return temp;
}
struct node* create_node(int v)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->vertice=v;
    temp->next=NULL;
    return temp;
};
void add_edge(struct graph* g,int i,int j)
{
    struct node* temp=create_node(i);
    temp->next=g->adjList[j];
    g->adjList[j]=temp;
    temp=create_node(j);
    temp->next=g->adjList[i];
    g->adjList[i]=temp;
}
void print_adjlist(struct graph* g)
{

    for(int i=0;i<g->numvertices;i++)
    {
        struct node* temp=g->adjList[i];
        printf("Edge %d:",i);
        while(temp)
        {
            printf("%d->",temp->vertice);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    struct graph* g=create_graph(4);
    add_edge(g,0,1);
    add_edge(g,1,3);
    add_edge(g,2,1);
    add_edge(g,0,3);
    print_adjlist(g);
}