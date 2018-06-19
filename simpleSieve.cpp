#include<bits/stdc++.h>
using namespace std;
bool isPrime[100002];
int main()
{
    memset(isPrime,true,sizeof(isPrime));
    int n;
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(isPrime[i])
        for(int k=i*2;k<=n;k+=i)
        {
             if(isPrime[k])
                isPrime[k]=false;
        }
    }
    for(int i=2;i<=n;i++)
        if(isPrime[i])cout<<i<<" ";
}
