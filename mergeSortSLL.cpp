#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
void insert_at_begin(int e, node *&start)
{
    node *ptr=new node();
    ptr->data=e;
    if(!start)
        ptr->next=NULL;
    else ptr->next=start;
    start=ptr;
}
node * findMiddle(node *start)
{
    node *slow,*fast;
    slow=fast=start;
    while(fast && fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node * mergeSorted(node *beg1, node *beg2)
{
    node *prev,*start,*ptr;
    prev=start=NULL;
    while(beg1 && beg2)
    {
        if(beg1->data <= beg2->data)
        {
            ptr=beg1;
            beg1=beg1->next;
        }
        else {
            ptr=beg2;
            beg2=beg2->next;
        }
        if(!start)
        {
            start=prev=ptr;
        }
        else {
                prev->next=ptr;
                prev=ptr;
        }
    }
    while(beg1)
    {
        prev->next=beg1;
        prev=beg1;
        beg1=beg1->next;
    }
    while(beg2)
    {
        prev->next=beg2;
        prev=beg2;
        beg2=beg2->next;
    }
    return start;
}

node * mergeSort(node *start)
{
    if(!start||!start->next)return start;
    node *ptr = findMiddle(start);
    //cout<<ptr->data<<"mid\n";
    node *mid = ptr->next;
    ptr->next = NULL;
    node *beg1 = mergeSort(start);
    node *beg2 = mergeSort(mid);
    node *head = mergeSorted(beg1, beg2);
    //cout<<head->data<<"hi\n";
    return head;
}
node * rev(node *prev, node *curr)
{
    while(curr)
    {
        node *post=curr->next;
        curr->next=prev;
        prev=curr;
        curr=post;
    }
    return prev;
}
void display(node *ptr)
{
    while(ptr)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<"\n";
}
int main()
{
    int n,e;
    cin>>n;
    node *start=NULL;
    while(n--)
    {
        cin>>e;
        insert_at_begin(e, start);
    }
    cout<<"Inserted: ";
    display(start);
    cout<<"Sorted: ";
    display(mergeSort(start));
}
