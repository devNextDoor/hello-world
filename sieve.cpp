#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> pr;
bool prime[1000002],mnd=0;
int mn=0,mx=0;
void simSieve(int l)
{
    pr.clear();
    for(int p=2;p*p<l;p++)
    {
        if(prime[p])
        {
            for(int j=p*p;j<l;j+=p)
                prime[j]=false;
        }
    }
}
void Sieve(long n)
{
    int l=sqrt(n)+1;long low,high,r;
    simSieve(l);//cout<<".";
    low=l; high=2*l;
    //if(high>n)high=n;
    while(low<n)
    {   memset(prime,true,sizeof(prime));
        for(int i=0;i<pr.size();i++)
        {
            r=(low/pr[i])*pr[i];
            if(r<low)r+=pr[i];
            for(long k=r;k<high;k+=pr[i])
                prime[k-low]=false;
        }
        for(int i=low;i<high;i++)
            if(prime[i-low])
            {
                pr.push_back(i);
            }
        low+=l;
        high+=l;
        if(high>n)high=n+1;
    }
}
int main()
{
    long n,q,m;
    cin>>q;
    memset(prime,true,sizeof(prime));
    simSieve(1000000);
    //cout<<pr[0]<<" "<<pr[]<<"\n";
    while(q--)
    {cin>>m>>n;
     mnd=0; mx=mn=0;
     for(int i=m,j=n;i<=j;)
     {
         if(prime[i]&&mn==0)mn=i;
         else if(!prime[i]&&mn==0)i++;
         if(prime[j]&&mx==0)mx=j;
         else if(!prime[j]&&mx==0)j--;
         if(mn!=0&&mx!=0)break;
     }
     cout<<mx-mn<<"\n";
    }
}
