/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<stack>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head,*h,*temp;
        h=new ListNode(0);
        h->next=head;
        int len=1;//链表长度
        while(p->next){
            p=p->next;
            len++;
        }
        if(n==len||len==1){
            //要删除第一个元素
            h->next=head->next;
            delete head;
            return h->next;
        }
        int num=1;
        p=head;
        while(num!=len-n){
            p=p->next;
            num++;
        }//要删除的前一个元素
        temp=p->next;
        p->next=temp->next;
        delete temp;
        return h->next;
    }
};