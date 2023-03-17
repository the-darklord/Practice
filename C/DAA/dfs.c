#include <stdio.h>

int n=4;
static int count=0;

void dfs(int A[][10],int visited[],int v,int push[],int pop[])
{
    count++;
    visited[v]=0;
    for(int i=0;i<n;i++)
    {
        if(A[v][i]&&!visited[i])
        {
            push[v]=count;
            dfs(A,visited,i,push,pop);
            pop[v]=n-count;
            printf("Push : %d\nPop : %d\n\n",push[v],pop[v]);
        }
    }
}

void DFS(int A[][10],int visited[],int push[],int pop[])
{
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(A,visited,i,push,pop);
        }
    }
}

void main()
{
    int adj[n][n];
    int visited[n],push[n],pop[n];
    printf("Enter Adjacency Matrix : \nEnter \n1 for YES\n2 for NO\n");
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        push[i]=0;
        pop[i]=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    DFS(adj,visited,push,pop);
}