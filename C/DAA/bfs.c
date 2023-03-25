/*
ALGORITHM BFS(G)
    mark each vertex with 0
    count ← 0
    for each vertex v in V
        if v is marked with 0
            bfs(v)

bfs(v)
    count ← count + 1
    mark v with count
    add v to queue
    while queue is not empty
        for each vertex w in V adjacent to the front vertex
            if w is marked with 0
                count ← count + 1
                add w to queue
        remove front vertex from queue
        
*/

#include <stdio.h>
#include <stdlib.h>

int n;
int *visited;
int **adj;

typedef struct QUEUE
{
    int *arr;
    int f,r;
}QUEUE;

QUEUE q;

void enq(int k)
{
    q.arr[++(q.r)]=k;
}

int deq()
{
    int t=q.f;
    if((q.f)+1==q.r)
    {
        q.f=q.r=-1;
        return q.arr[++t];
    }
    return q.arr[++(q.f)];
}

void BFS()
{
    int i=deq();
    while(q.f<=q.r)
    {
        printf("%d ",i);
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]&&!visited[j])
            {
                visited[j]=1;
                enq(j);
            }
        }
        i=deq();
    }
}

void main()
{
    q.f=q.r=-1;
    q.arr=(int *)malloc(n*sizeof(int));
    printf("Enter No. of Vertices : \t");
    scanf("%d",&n);
    visited=(int *)malloc(n*sizeof(int));
    adj=(int **)calloc(n,sizeof(int *));
    printf("Enter %d*%d Adjacency Matrix : \n",n,n);
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        adj[i]=(int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nBFS ORDER IS : \n");
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            enq(i);
            BFS();
        }
    }
    printf("\n\n");
}