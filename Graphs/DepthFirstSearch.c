#include<stdio.h>
#include<stdlib.h>
struct node
{
    int vertice;
    struct node* next;
};
struct graph{
  int numvertice;
  int* visited;
  struct node** adjlist;  
};
struct node* create_node(int v)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->vertice=v;
    temp->next=NULL;
    return temp;
}
struct graph* create_graph(int v)
{
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->numvertice=v;
    g->visited=malloc(v*sizeof(int));
    g->adjlist=malloc(v*sizeof(struct node*));
    for(int i=0;i<v;i++)
    {
        g->visited[i]=0;
        g->adjlist[i]=NULL;
    }
    return g;
    
}
void add_edge(struct graph* g,int i,int j)
{
    struct node* temp=create_node(i);
    temp->next=g->adjlist[j];
    g->adjlist[j]=temp;
    temp=create_node(j);
    temp->next=g->adjlist[i];
    g->adjlist[i]=temp;
}
void bfs(struct graph* g,int v)
{
    struct node* temp=g->adjlist[v];
    g->visited[v]=1;
    printf("%d ",v);
    while(temp)
    {
        int connected=temp->vertice;
        if(g->visited[connected]==0)
        {
            bfs(g,connected);
        }
        temp=temp->next;
    }
}
int main()
{
    struct graph* g=create_graph(4);
    add_edge(g,0,1);
    add_edge(g,1,3);
    add_edge(g,2,1);
    add_edge(g,0,3);
    bfs(g,0);
}