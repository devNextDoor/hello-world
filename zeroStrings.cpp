#include<bits/stdc++.h>
using namespace std;
int fn(int n)
{
    if(n==0)return 0;
    int f[n+2][2];
    f[0][1]=f[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        f[i][0]=f[i][1]=f[i-1][1];
        f[i][1]+=f[i-1][0];
    }
    return f[n][1];
}
int main()
{
    int n;
    cin>>n;
    cout<<fn(n);
}
