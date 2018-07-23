#include<bits/stdc++.h>
using namespace std;
int kadane(vector<int> a)
{
    int n=a.size(),mxSum=INT_MIN,ind,sum=0,st;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum<0)sum=0;
        else if(sum>mxSum)
        {
            mxSum=sum;
            ind=i;
        }
    }
    sum=0;
    for(int i=ind;i>=0;i--)
    {
        sum+=a[i];
        if(sum==mxSum)
        {
            st=i;
            break;
        }
    }
    cout<<st<<" "<<ind<<" "<<mxSum;
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
    kadane(arr);
}
