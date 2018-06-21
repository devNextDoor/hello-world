#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int i,int n)
{
    int p=2*i,q=2*i+1,largest=i;
    if(p<=n && a[p]>a[largest])
        largest=p;
    if(q<=n && a[q]>a[largest])
        largest=q;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        heapify(a,largest,n);
    }
}
void build_heap(int a[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        heapify(a,i,n);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n+2];
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    build_heap(arr,n);
    for(int i=n;i>1;i--)
    {
        swap(arr[1],arr[i]);
        heapify(arr,1,i-1);
    }
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
}
