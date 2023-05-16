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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0, l2=0;
        ListNode *t1 = headA, *t2=headB;
        while(t1!=NULL){
            t1=t1->next;
            l1++;
        }
        while(t2!=NULL){
            t2=t2->next;
            l2++;
        }
        while(l1>l2){
            headA=headA->next;
            l1--;
        }
        while(l2>l1){
            headB=headB->next;
            l2--;
        }
        while(headA!=NULL || headB!=NULL){
            if(headA==headB) return headA;
            else {
                headA=headA->next;
                headB=headB->next;
            }
        }
        return NULL;
    }
};