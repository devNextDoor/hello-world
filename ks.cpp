#include<bits/stdc++.h>
using namespace std;
int p[10],w[10],mem[10][100];
int ks(int n,int W)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(j<w[i])
            {
                mem[i][j]=mem[i-1][j];
            }
            else
            {
                mem[i][j]=max(mem[i-1][j],p[i]+mem[i-1][j-w[i]]);
            }
        }
    }
    return mem[n][W];
}
int main()
{
    int n,W;
    cin>>n>>W;
    for(int i=1;i<=n;i++)
        cin>>p[i]>>w[i];
    cout<<ks(n,W);
}
