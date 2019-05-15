#include<bits/stdc++.h>
#define PII pair<long,int>
#define LONG_MAX 1000000000
using namespace std;
vector<PII> adj[10002];
bool vis[10002];
long dist[10002];
void dijkstra()
{
    priority_queue<PII,vector<PII>,greater<PII> > Q;
    Q.push(make_pair(0,1));
    dist[1]=0;
    while(!Q.empty())
    {
        PII f=Q.top();
        int n=f.second;
        Q.pop();
        if(vis[n])continue;
        vis[n]=true;
        for(int i=0;i<adj[n].size();i++)
        {
            int e=adj[n][i].first; long w=adj[n][i].second;
            if(!vis[e] && dist[e]>dist[n]+w)
            {
                    dist[e]=(dist[n]+w);
                    Q.push(make_pair(dist[e],e));
            }
        }
    }
}
int main()
{
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        dist[i]=LONG_MAX;
        vis[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(y,w));       
        adj[y].push_back(make_pair(x,w));
    }
    dijkstra();
    for(int i=2;i<=n;i++)
        cout<<dist[i]<<" ";
}
