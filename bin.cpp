#include<bits/stdc++.h>
using namespace std;
void fn(int d,int n,int k)
{
    if(d==0)return;
    fn(d-1,n,k<<1);
    if(n & k)
        cout<<"1";
    else cout<<"0";
}
int main()
{
    int n;
    cin>>n;
    int d,k=1;
    if(n==0)d=1;
    else d=floor(log10(n)/log10(2)+1);
    fn(d,n,k);
}
