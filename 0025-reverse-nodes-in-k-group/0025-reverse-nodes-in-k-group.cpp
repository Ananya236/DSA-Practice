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
    ListNode* getGroupStart(ListNode* curStart, int k){
        ListNode *temp = NULL;
        while(k && curStart){
            temp = curStart;
            curStart = curStart->next;
            k--;
        }
        if(k==0) return temp;
        return NULL;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev, *curr, *groupSt, *newHead;
        curr=head;
        
        while(curr!=NULL){
            int cnt = k;
            groupSt=curr;
            prev=NULL;
            while(cnt){
                ListNode *temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
                cnt--;
            }
            if(head==groupSt){
                newHead = prev;
            }
            ListNode* newGroupSt = getGroupStart(curr, k);
            if(newGroupSt){
                groupSt->next = newGroupSt;
            }
            else{
                groupSt->next = curr;
                break;
            }
        }
        return newHead;
    }
};