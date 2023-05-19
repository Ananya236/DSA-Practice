/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //At this point slow pointer is at mid of ll and fast is at end
        
        //Now we will reverse the remaining half of ll using slow as head for second half
        ListNode *prev=NULL, *nxt;
        while(slow){
            nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }
        
        //Now prev pointer is at the head of reversed ll or we can say end of ll
        fast=head;
        slow=prev;
        
        //since slow starts with prev, it will end in between of ll
        while(slow){
            if(slow->val != fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
        
        return true;
    }
};