#include<bits/stdc++.h>
#include<stdio.h>
#include<limits.h>
#include<map>
#define scl1(x) scanf("%ld",&x)
#define sci1(x) scanf("%d",&x)
#define sci2(x,y) scanf("%d%d",&x,&y)
#define mpr(x,y) make_pair(x,y)
using namespace std;

void dfs(int s)
{
    vis[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(!vis[adj[s][i]])
            dfs(adj[s][i]);
    }
}

void bfs(int s)
{
    queue<int> Q;
    Q.push(s);
    vis[s]=true;
    while(!Q.empty())
    {
        int p=Q.front();
        Q.pop();
        for(int i=0;i<adj[p].size();i++)
        {
            if(!vis[adj[p][i]])
            {
                vis[adj[p][i]]=true;
                Q.push(adj[p][i]);
            }
        }
    }
}
