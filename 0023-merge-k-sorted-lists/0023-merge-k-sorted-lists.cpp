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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, compare> minHeap;
    
        for (auto list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }
    
        ListNode merged(0);
        ListNode* tail = &merged;
    
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            
            tail->next = node;
            tail = node;
            
            if (node->next) {
                minHeap.push(node->next);
            }
        }
        
        return merged.next;
    }
};