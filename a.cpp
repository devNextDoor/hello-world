#include<bits/stdc++.h>
#include<queue>
using namespace std;
vector<int> adj[100];
int indeg[100];
queue<int> in_zero;
void top_sort()
{
    while(!in_zero.empty())
    {
        int p=in_zero.front();
        in_zero.pop();
        cout<<p<<" ";
        for(int i=0;i<adj[p].size();i++)
        {
            indeg[adj[p][i]]--;
            if(indeg[adj[p][i]]==0)
            {
                in_zero.push(adj[p][i]);
            }
        }
    }
}
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        adj[i].clear();
    memset(indeg,0,sizeof(indeg));
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        indeg[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            in_zero.push(i);
        }
    }
    top_sort();
}
