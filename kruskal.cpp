#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int> > > v;
vector<pair<int,int> > mst;
long minCost=0;
int p[100002],r[100002];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int parent(int i)
{
    if(p[i]==i)return i;
    return p[i]=parent(p[i]);
}
void unin(int x,int y)
{
    int px=parent(x),py=parent(y);
    if(r[px]<=r[py])
    {
        p[px]=py;
        if(r[px]==r[py])
            r[py]++;
    }
    else
    {
        p[py]=px;
    }
}
void kruskal(int n)
{
    init(n);
    for(int i=0;i<v.size();i++)
    {
        int n1=v[i].second.first,n2=v[i].second.second,w=v[i].first;
        if(parent(n1)!=parent(n2))
        {
            minCost+=w;
            unin(n1,n2);
            mst.push_back(make_pair(n1,n2));
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
        v.push_back(make_pair(w,make_pair(x,y)));
    }
    sort(v.begin(),v.end());
    kruskal(n);
    for(int i=0;i<mst.size();i++)
    {
        cout<<mst[i].first<<" "<<mst[i].second<<"\n";
    }
    cout<<minCost;
}
