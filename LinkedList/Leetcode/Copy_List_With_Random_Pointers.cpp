/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        Node *curr = head;

        // Step 1. Create Clone Linked List and point each new node to its corresponding OG node 1->1|2->2
        while(curr){
            Node *temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;

            curr = temp->next; // we landed on second/nth OG LL Node 
        }   

        //Step 2. Attach Random pointer in clone LL
        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Detach both LL from each other
        Node *result = head->next, *temp = head->next;
        curr = head;

        while(curr){
            // point OG node to OG node using temp
            curr->next = temp->next;
            curr = curr->next;

            // point dup node to next dup node using curr
            // edgde case :- if curr becomes NULL at last node
            if(curr){
                temp->next = curr->next;
                temp = temp->next;
            }
        }

        return result;
    }
};