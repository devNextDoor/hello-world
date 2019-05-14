#include<bits/stdc++.h>
#define PII pair<long,int>
using namespace std;
void fn(int d, int n)
{
    if(d==0)return;
    cout<<((n&1<<(d-1))?1:0);
    fn(d-1,n);
}
int main()
{
    int n,d=0;
    cin>>n;
    if(!n)d=1;
    if(!d)d=floor(log10(n)/log10(2)+1);
    fn(d,n);
}
