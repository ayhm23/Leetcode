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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         //reverse - remove nth from back - reverse again

//         ListNode * temp = head, * prev = NULL;
//         while(temp){
//             ListNode *next = temp->next;
//             temp->next = prev;
//             prev = temp; temp = next;
//         }
//         int i = 1;
//         //prev at last node
//         temp = prev; prev = NULL;
//         while(temp){
//             if(i == n){
//                 temp = temp->next;
//                 i++;
//             }else{
//                 ListNode * next = temp->next;
//                 temp->next = prev;
//                 prev = temp;
//                 temp = next;
//                 i++;
//             }
//         }
//         return prev;
//     }
// };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete nth node from end
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        return dummy.next;
    }
};
