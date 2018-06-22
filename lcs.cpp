#include<bits/stdc++.h>
using namespace std;
int mem[20][20];
string x,y,c;
int lcs(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
                mem[i][j]=1+mem[i-1][j-1];
            else mem[i][j]=max(mem[i-1][j],mem[i][j-1]);
        }
    }
    return mem[n][m];
}
void common_seq(int i,int j)
{
    if(i==0||j==0)return;
    if(mem[i][j]==mem[i][j-1])
        common_seq(i,j-1);
    else if(mem[i][j]==mem[i-1][j])
        common_seq(i-1,j);
    else if(mem[i][j]==mem[i-1][j-1]+1)
    {
        c.push_back(y[j-1]);
        common_seq(i-1,j-1);
    }
}
int main()
{
    cin>>x>>y;
    int n=x.length(),m=y.length();
    cout<<lcs(n,m)<<"\n";
    common_seq(n,m);
    reverse(c.begin(),c.end());
    cout<<c;
}
