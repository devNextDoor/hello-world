#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,d=0;
    cin>>n;
    while(n)
    {
        n=n>>1;
        d++;
    }
    cout<<(1<<d);
}
