#include<bits/stdc++.h>
#include<stdio.h>
#define sci1(x) scanf("%d",&x)
#define sci2(x,y) scanf("%d%d",&x,&y,&z)
#define sci3(x,y,z) scanf("%d%d%d",&x,&y,&z)
using namespace std;
vector<int> adj[100002];
int n,p[100002],r[100002],c[100002];
void initialize()
{
    for(int i=1;i<=n;i++)
    {
        r[i]=0;
        p[i]=i;
        c[i]=0;
        adj[i].clear();
    }
}
int parent(int k)
{
    if(k==p[k])return k;
    p[k]=parent(p[k]);
    return p[k];
}
void unin(int x,int y)
{
    int px=parent(x),py=parent(y);
    if(px==py)return;
    if(r[px]<r[py])swap(px,py);
    p[py]=px;
    if(r[px]==r[py])r[px]++;
}
int main()
{
    int x,y,z,q,k;
    sci1(n); k=n; initialize();
    k--;
    while(k--)
    {
        sci2(x,y);
        adj[++x].push_back(++y);
        adj[y].push_back(x);
    }
    sci1(q);
    while(q--)
    {
        sci3(x,y,z);
        if(x==1)
        {
            c[++y]=z; //cout<<y<<"*";
            for(int i=0;i<adj[y].size();i++)
            {
                if(c[adj[y][i]]==c[y])
                {unin(adj[y][i],y);}
            }
        }
        else
        {
            if(parent(++y)==parent(++z))
                {printf("YES\n");}
            else {printf("NO\n");}
        }
    }
}
