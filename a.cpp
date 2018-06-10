#include<bits/stdc++.h>
#include<queue>
using namespace std;
vector<int> adj[100];
queue<int> Q;

void bfs(int num)
{
    while(!Q.empty())
    {
        int p=Q.front(),next1=-1,next2=-1;
        Q.pop();
        cout<<p<<" ";
        int r=p%10;
        if(r==0)
            next2=p*10+1;
        else if(r==9)
            next1=p*10+8;
        else{
            next1=p*10+(p%10-1);
            next2=p*10+(p%10+1);
        }

        if(next1!=-1)
        {
            if(next1>num)continue;
            Q.push(next1);
        }
        if(next2!=-1)
        {
            if(next2>num)continue;
            Q.push(next2);
        }
    }
}
void jumping_num(int num)
{
    cout<<"0 ";
    for(int i=1;i<=9;i++)
    {
        if(i>num)break;
        Q.push(i);
        bfs(num);
    }
}
int main()
{
    int n;
    cin>>n;
    if(n>=0)jumping_num(n);
}
