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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
        return head;

        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr){
            if(curr->val == val){ // if match
                // if its the first node
                if(head == curr){
                    head = curr->next;
                    curr = curr->next;
                }
                // if its last node
                else if(!curr->next){
                    prev->next = NULL;
                    curr = curr->next;
                }
                // middle node
                else{
                    prev->next = curr->next;
                    curr = curr->next;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};