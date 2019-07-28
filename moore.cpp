//Moore's Voting Algo for majority element in array
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, arr[10];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int prev=arr[0],cnt=1;
    for(int i=1; i<n; i++)
    {
        if(arr[i]==prev)
        {
            cnt++;
        }
        else if(cnt>0)
        {
            cnt--;
        }
        else
        {
            prev=arr[i];
            cnt=1;
        }
    }
    if(cnt>0)
    {
        cnt=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==prev)
                cnt++;
        }
        prev=(cnt>n/2)?prev:-1;
    }
    else prev=-1;
    cout<<prev<<"\n";
}
