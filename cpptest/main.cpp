#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *insertionSortList(ListNode *head) {
        if(!head)
            return NULL;
        ListNode *p=head->next,*q,*preq,*res=head,*prep=head;
        while(p)
        {
            q=res;
            while(q!=p && q->val<=p->val)
            {
                preq=q;
                q=q->next;
            }
            if(q==p)
            {
                prep=p;
                p=p->next;
                continue;
            }
            if(q==res)
            {
                prep->next=p->next;
                p->next=res;
                res=p;
                p=prep->next;
            }
            else
            {
                prep->next=p->next;
                p->next=q;
                preq->next=p;
                p=prep->next;
            }
        }
        return res;
    }

int main()
{
    ListNode *head=new ListNode(1);
    head->next=new ListNode(1);
    ListNode *r=insertionSortList(head);
    while(r)
    {
        cout<<r->val<<endl;
        r=r->next;
    }
    return 0;
}
