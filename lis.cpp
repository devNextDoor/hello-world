#include<bits/stdc++.h>
using namespace std;
int lis(vector<int> a)
{
    int n=a.size(),lis[n+1],mx=-1;
    lis[0]=1;
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[i]>a[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
        //cout<<lis[i]<<" ";
    }
    for(int i=0;i<n;i++)
        if(mx<lis[i])
            mx=lis[i];
    return mx;
}
int main()
{
    int n,e;
    vector<int> arr;
    arr.clear();
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>e;
        arr.push_back(e);
    }
    cout<<lis(arr);
}
