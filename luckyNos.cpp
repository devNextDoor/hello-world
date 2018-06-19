#include<bits/stdc++.h>
#include<map>
using namespace std;

int main()
{
    int n,k=2;
    cin>>n;
    while(1)
    {
        if(n<k)
        {
            cout<<"Lucky\n";
            break;
        }
        else if(n%k==0)
        {
            cout<<"Not lucky\n";
            break;
        }
        else
        {
            n-=n/k;
            k++;
        }
    }
}
