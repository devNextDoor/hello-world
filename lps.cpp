#include<bits/stdc++.h>
using namespace std;
int st;
bool table[100][100];
int lPalin(string str)
{
    memset(table,0,sizeof(table));
    int n=str.length(),l=1;
    st=0;
    for(int i=0; i<n; i++)
    {
        table[i][i]=1;
        if(i+1<n)
        {
            table[i][i+1]=(str[i]==str[i+1]);
            if(table[i][i+1])
            {
                l=2;
                st=i;
            }
        }
    }
    for(int k=2; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            if(i+k<n)
            {
                table[i][i+k]=((str[i]==str[i+k])&&table[i+1][i+k-1]);
                if((k+1>l) && table[i][i+k])
                {
                    l=k+1;
                    st=i;
                }
            }
        }
    }
    return l;
}
int main()
{
    string str;
    cin>>str;
    int l=lPalin(str);
    cout<<l<<" "<<str.substr(st,l)<<endl;
}
