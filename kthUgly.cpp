#include<bits/stdc++.h>
using namespace std;
long ugly(int p)
{
    vector<long> v;
    v.clear();
    v.push_back(1);
    int i=0,j=0,k=0;
    while(v.size()<p)
    {
        if(v[i]*2<=v[j]*3 && v[i]*2<=v[k]*5)
        {
            if(v[v.size()-1]!=v[i]*2)v.push_back(v[i]*2);
            i++;
        }
        else if(v[j]*3<=v[k]*5 && v[j]*3<=v[i]*2)
        {
            if(v[v.size()-1]!=v[j]*3)v.push_back(v[j]*3);
            j++;
        }
        else if(v[k]*5<=v[i]*2 && v[k]*5<=v[j]*3)
        {
            if(v[v.size()-1]!=v[k]*5)v.push_back(v[k]*5);
            k++;
        }
    }
    return v[p-1];
}
int main()
{
    int k;
    cin>>k;
    cout<<ugly(k);
    return 0;
}
