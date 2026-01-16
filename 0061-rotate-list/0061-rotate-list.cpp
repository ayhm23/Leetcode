class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: compute length
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Step 2: normalize k
        k = k % len;
        if (k == 0) return head;

        // Step 3: find new tail (len - k - 1)
        ListNode* temp = head;
        for (int i = 1; i < len - k; i++) {
            temp = temp->next;
        }

        // Step 4: rotate
        ListNode* newHead = temp->next;
        temp->next = NULL;
        tail->next = head;

        return newHead;
    }
};
