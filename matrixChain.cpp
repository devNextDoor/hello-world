#include<bits/stdc++.h>
using namespace std;
int s[100][100];
int mat_mul(int n,int p[])
{
    int m[100][100];
    for(int d=0;d<n;d++)
    {
        for(int i=1;i<=n;i++)
        {
            int j=i+d;
            if(j>n)break;
            if(i==j)
            {
                m[i][j]=0;
                s[i][j]=i;
            }
            else
            {
                m[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                    if(q<m[i][j])
                    {
                        m[i][j]=q;
                        s[i][j]=k;
                    }
                }
            }
        }
    }
    cout<<s[1][n]<<" ";
    return m[1][n];
}
int main()
{
    int n;
    cin>>n;
    int p[n+2];
    for(int i=0;i<=n;i++)
        cin>>p[i];
    cout<<mat_mul(n,p);
}
