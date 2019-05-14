#include<bits/stdc++.h>
using namespace std;

int bin_search(int a[],int l,int r,int e)
{
    if(l>r)return -1;
    int m=(l+r)/2;
    if(a[m]==e)
        return m;
    else if(a[m]>e)
        bin_search(a,l,m-1,e);
    else if(a[m]<e)
        bin_search(a,m+1,r,e);
}
int main()
{
    int n,e;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>e;
    cout<<bin_search(arr,0,n-1,e);
}
