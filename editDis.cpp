#include<bits/stdc++.h>
using namespace std;
int editDistance(string s1, string s2)
{
    int n=s1.length(),m=s2.length(),C[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0)
                C[i][j]=j;
            else if(j==0)
                C[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                C[i][j]=C[i-1][j-1];
            else C[i][j]=min(min(1+C[i][j-1],1+C[i-1][j]),1+C[i-1][j-1]);
        }
    }
    return C[n][m];
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<editDistance(s1,s2);
}
