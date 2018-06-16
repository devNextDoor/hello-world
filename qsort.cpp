#include<bits/stdc++.h>
using namespace std;

int part(int a[],int low,int high)
{
    int i=low-1,pivot=a[high];
    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return (i+1);
}
void quick_sort(int a[],int low,int high)
{
    if(low<high)
    {
        int pi=part(a,low,high);
        quick_sort(a,low,pi-1);
        quick_sort(a,pi+1,high);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

}
