// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = NULL;
//         ListNode* curr = head;

//         while (curr != NULL) {
//             ListNode* next = curr->next;  // store next
//             curr->next = prev;            // reverse link
//             prev = curr;                  // move prev
//             curr = next;                  // move curr
//         }

//         return prev;  // new head
//     }
// };


// recursion

class Solution {
public:
    ListNode* rev(ListNode* head, ListNode* prev) {
        if (head == NULL)
            return prev;

        ListNode* nextNode = head->next;
        head->next = prev;
        return rev(nextNode, head);
    }

    ListNode* reverseList(ListNode* head) {
        return rev(head, NULL);
    }
};


