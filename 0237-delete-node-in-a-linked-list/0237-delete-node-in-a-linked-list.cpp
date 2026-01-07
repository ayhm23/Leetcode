/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode * temp = node->next;
        ListNode * curr = node;

        while(temp != NULL){
            curr->val = temp->val;
            if(temp->next == NULL){
                curr->next = NULL;
                break;
            }
            else{
                curr = temp;
                temp = temp->next;
            }
        }
        return;
    }
};