/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0),*point=head;
        int add=0;
        while(l1&&l2){
            int temp=l1->val+l2->val;
            if(add){
                add--;
                temp++;
            }
            if(temp>=10){
                temp-=10;
                add++;
            }
            point->val=temp;
            if(l1->next&&l2->next){
                point->next=new ListNode(0);
                point=point->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        if(l1){
            point->next=l1;
            //point=point->next;
        }
        else if(l2){
            point->next=l2;
            //point=point->next;
        }
        while(add){
            /**/
            if(point->next){
                point=point->next;
                point->val+=add;
                add--;
                if(point->val>=10){
                    point->val-=10;
                    add++;
                }
            }
            else{
                point->next=new ListNode(0);
                point=point->next;
                point->val=add;
                point->next=NULL;
                add--;
            }
        }
        return head;
    }
};