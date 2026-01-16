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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //reverse - remove nth from back - reverse again

        ListNode * temp = head, * prev = NULL;
        while(temp){
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp; temp = next;
        }
        int i = 1;
        //prev at last node
        temp = prev; prev = NULL;
        while(temp){
            if(i == n){
                temp = temp->next;
                i++;
            }else{
                ListNode * next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
                i++;
            }
        }
        return prev;
    }
};