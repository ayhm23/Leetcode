class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        // Step 1: connect tail of A to headA
        ListNode* tail = headA;
        while (tail->next)
            tail = tail->next;
        tail->next = headA;

        // Step 2: Floyd's cycle detection on B
        ListNode *slow = headB, *fast = headB;
        bool hasCycle = false;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle) {
            tail->next = NULL;   // restore
            return NULL;
        }

        // Step 3: find cycle entry = intersection
        slow = headB;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        tail->next = NULL;   // restore
        return slow;
    }
};
