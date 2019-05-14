#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
vector<PII> adj[100002];
bool vis[100002];
long dist[100002];
void dijkstra()
{
    memset(vis,false,sizeof(vis));
    memset(dist,200000,sizeof(dist));
    priority_queue<PII,vector<PII>,greater<PII> > Q;
    Q.push(make_pair(0,1));
    vis[1]=true;
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
                if(dist[adj[n][i].first]>dist[n]+adj[n][i].second)
                {
                    dist[adj[n][i].first]=(dist[n]+adj[n][i].second);
                }
                Q.push(make_pair(adj[n][i].second,adj[n][i].first));
        }
    }
}
int main()
{
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(y,w));
        adj[y].push_back(make_pair(x,w));
    }
    dijkstra();
    for(int i=1;i<=n;i++)
        cout<<dist[i]<<"\n";
}
