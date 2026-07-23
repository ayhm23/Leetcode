class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head) return nullptr;


        // Step 1: Insert copy after every node
        Node* cur = head;

        while(cur){

            Node* copy = new Node(cur->val);

            copy->next = cur->next;
            cur->next = copy;

            cur = copy->next;
        }


        // Step 2: Assign random pointers
        cur = head;

        while(cur){

            if(cur->random)
                cur->next->random = cur->random->next;

            cur = cur->next->next;
        }


        // Step 3: Separate original and copied list
        Node* dummy = new Node(0);
        Node* copyCur = dummy;

        cur = head;

        while(cur){

            Node* copy = cur->next;

            // restore original
            cur->next = copy->next;

            // build copy list
            copyCur->next = copy;
            copyCur = copy;

            cur = cur->next;
        }


        return dummy->next;
    }
};