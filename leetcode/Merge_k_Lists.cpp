/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge_2_lists(ListNode *l1,ListNode *l2) {
        ListNode *p1=l1,*p2=l2,*p,*p_head,*temp;
        p=new ListNode(0);
        p_head=p;
        while(p1&&p2){
            if(p1->val<p2->val){
                p->next=p1;
                p1=p1->next;
                p=p->next;
                continue;
            }
            else{
                p->next=p2;
                p2=p2->next;
                p=p->next;
            }
        }
        if(!p1)
            //p1全部遍历完成，把p2接在后面
            p->next=p2;
        else
            p->next=p1;
        temp=p_head->next;
        delete p_head;
        return temp;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1)
            return lists[0];
        ListNode *p=lists[0];
        for(int i=1;i<lists.size();i++)
            p=merge_2_lists(p,lists[i]);
        return p;
    }
};