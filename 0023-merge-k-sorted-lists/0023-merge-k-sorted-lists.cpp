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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<ListNode *> pointers(k);
        ListNode* merged = new ListNode();
        ListNode* tail = merged;

        for(int i=0;i<k;i++){
            pointers[i] = lists[i];
        }

        while(true){
            int minNum = INT_MAX;
            int minIndex = -1;
            bool isAllNull = true;
            for(int j=0;j<k;j++){
                if(pointers[j] && pointers[j]->val < minNum){
                    minNum = pointers[j]->val;
                    minIndex = j;
                    isAllNull = false;
                }
            }
            if(isAllNull) break;
            ListNode* temp = new ListNode(minNum);
            tail->next = temp;
            tail = tail->next;
            if(pointers[minIndex]){
                pointers[minIndex]=pointers[minIndex]->next;
            }
        }

        return merged->next;
    }
};