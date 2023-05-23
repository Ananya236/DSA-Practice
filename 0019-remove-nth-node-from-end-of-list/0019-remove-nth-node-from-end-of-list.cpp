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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode *temp = head;
        while(temp){
            temp=temp->next;
            len++;
        }
        if(len==n) {
            head=head->next;
            return head;
        }
        int i=1;
        temp=head;
        while(temp){
            if(i==len-n){
                temp->next=temp->next->next;
                break;
            }
            temp=temp->next;
            i++;
        }
        
        return head;
    }
};