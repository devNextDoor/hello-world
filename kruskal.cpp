#include<bits/stdc++.h>
#include<stdio.h>
#define sci2(x,y) scanf("%d%d",&x,&y)
#define sci3(x,y,z) scanf("%d%d%d",&x,&y,&z)
using namespace std;
typedef pair<int,pair<int,int> > PII;
int pi[10002],r[10002],n,m;
void initialize()
{
    for(int i=1;i<=n;i++)
    {
        r[i]=0;
        pi[i]=i;
    }
}
int parent(int k)
{
    if(pi[k]==k)return k;
    pi[k]=parent(pi[k]);
    return pi[k];
}
void unin(int x,int y)
{
    if(r[x]<r[y])
        swap(x,y);
    pi[y]=x;
    if(r[x]==r[y])
        r[x]++;
}
long kruskal(PII p[])
{
    long c=0;
    for(int i=0;i<m;i++)
    {
       int a=p[i].second.first,b=p[i].second.second,w=p[i].first;
       int px=parent(a),py=parent(b);
       if(px!=py)
       {
           c+=w;
           //cout<<a<<" "<<b<<" "<<w<<"\n";
           unin(px,py);
       }
    }
       return c;
}
int main()
{
    int a,b,w; PII p[100002];
    sci2(n,m);
    initialize();
    for(int i=0;i<m;i++)
    {
        sci3(a,b,w);
        p[i]=make_pair(w,make_pair(a,b));
    }
    sort(p,p+m);
    printf("%ld\n",kruskal(p));
}
