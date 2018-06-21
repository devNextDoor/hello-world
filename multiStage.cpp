#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adj[10];
int mn_path[10];
int fn(int s,int t)
{
    if(s==t)return mn_path[t]=0;
    if(mn_path[s]!=0)return mn_path[s];
    for(int i=0;i<adj[s].size();i++)
    {
        int p=adj[s][i].second+fn(adj[s][i].first,t);
        if(p<mn_path[s]||mn_path[s]==0)
            mn_path[s]=p;
    }
    return mn_path[s];
}
int main()
{
    int n,m,s,t,w,x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(y,w));
    }
    cin>>s>>t;
    cout<<fn(s,t);
}
