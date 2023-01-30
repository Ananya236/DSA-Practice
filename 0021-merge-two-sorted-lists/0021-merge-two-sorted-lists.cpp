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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *merged, *itr;
        merged = new ListNode();
        itr = merged;
        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                itr->next = list1;
                list1 = list1->next;
            } else {
                itr->next = list2;
                list2 = list2->next;
            }
            itr = itr->next;
        }
        while(list1!=NULL){
            itr->next = list1;
            list1 = list1->next;
            itr = itr->next;
        }
        while(list2!=NULL){
            itr->next = list2;
            list2 = list2->next;
            itr = itr->next;
        }
        return merged->next;
    }
};