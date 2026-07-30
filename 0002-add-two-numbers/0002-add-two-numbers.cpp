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
    ListNode* add(int carry, ListNode* l1, ListNode* l2){
        if(!l1 && !l2 && !carry){
            return nullptr;
        }
        int curr = carry;
        curr += (l1 ? l1->val : 0);
        curr += (l2 ? l2->val : 0);
        ListNode* ans = new ListNode(curr % 10);
        ans->next = add(curr/10, l1 ? l1->next : nullptr, l2 ? l2->next : nullptr);
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(0, l1, l2);
    }
};