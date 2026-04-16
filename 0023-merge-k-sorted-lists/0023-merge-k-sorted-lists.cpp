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
        if (lists.empty()) return nullptr;
        
        // Min-heap: {node->val, node}  → smallest value on top
        priority_queue<pair<int, ListNode*>, 
                       vector<pair<int, ListNode*>>, 
                       greater<pair<int, ListNode*>>> minHeap;
        
        // Step 1: Push the first node of every non-empty list into the heap
        for (ListNode* node : lists) {
            if (node) {
                minHeap.push({node->val, node});
            }
        }
        
        // Dummy node to build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        // Step 2: Keep popping the smallest node and adding next node from same list
        while (!minHeap.empty()) {
            auto [val, curr] = minHeap.top();
            minHeap.pop();
            
            tail->next = curr;      // attach to result
            tail = tail->next;
            
            // If this list has a next node, push it into the heap
            if (curr->next) {
                minHeap.push({curr->next->val, curr->next});
            }
        }
        
        return dummy->next;         // skip dummy
    }
};