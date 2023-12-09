#include<stdio.h>
#include<stdlib.h>
#define size 40
struct node
{
    int vertice;
    struct node* next;
};
struct graph
{
   int numvertice;
   int* visited;
   struct node** adjlist;
};
struct queue
{
    int front;
    int rear;
    int item[size];
};
struct queue* create_queue()
{
    struct queue* temp=malloc(sizeof(struct queue));
    temp->front=-1;
    temp->rear=-1;
    return temp;
} 
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
void enqueue(struct queue* q,int i)
{
    if(q->rear==size-1)
    {
        printf("Queue is full\n");
    }
    else{
        if(q->front==-1)
        q->front++;
        q->rear++;
        q->item[q->rear]=i;
    }
}
int dequeue(struct queue *q)
{
    if(q->front==-1)
    {
        printf("queue is empty\n");

    }
    else
    {
        int item;
        item=q->item[q->front];
        q->front++;
        if(q->front>q->rear)
        {
            //printf("Resetting queue\n");
            q->front=-1;
            q->rear=-1;
        }
        return item;
    }
    return -1;
}
int isempty(struct queue *q)
{
    if(q->front==-1)
    return 1;
    else
    return 0;
}
void bfs(struct graph* g,int start)
{
    struct queue* q=create_queue();
    g->visited[start]=1;
    enqueue(q,start);
    int currentnode;
    while(!isempty(q))
    {
        currentnode=dequeue(q);
        printf("%d ",currentnode);
        struct node* temp=g->adjlist[currentnode];
        
        while(temp)
        {
            
            if(g->visited[temp->vertice]==0)
            {
                g->visited[temp->vertice]=1;
                enqueue(q,temp->vertice);
            }
            temp=temp->next;

        }
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