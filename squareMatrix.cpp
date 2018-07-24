#include<bits/stdc++.h>
using namespace std;
long largestSquare(vector<int> m[],int n)
{
    long mx=0;
    for(int i=0;i<n;i++)
    {
        int k=m[i].size();
        for(int j=0;j<k;j++)
        {
            if(i!=0 && j!=0 && m[i][j]!=0)
                {
                    m[i][j]=min(min(m[i-1][j-1],m[i-1][j]),m[i][j-1])+1;
                    if(mx<m[i][j])mx=m[i][j];
                }
        }
    }
    return mx;
}
int main()
{
    int n,m,e;
    cin>>n>>m;
    vector<int> mat[n+1];

    for(int i=0;i<n;i++)
    {
        mat[i].clear();
        for(int j=0;j<m;j++)
        {
            cin>>e;
            mat[i].push_back(e);
        }
    }
    cout<<largestSquare(mat,n);
}
