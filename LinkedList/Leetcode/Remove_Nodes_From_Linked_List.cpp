// Brute Force Approach
class Solution {
public:

    void getReverse(ListNode* head, vector<int>&arr){
        if(!head)
        return;

        getReverse(head->next, arr);
        if(arr.empty())
        arr.push_back(head->val);
        else
        arr.push_back(max(arr.back(), head->val));
    }

    ListNode* removeNodes(ListNode* head) {
        vector<int>rev;
        // get reverse and right position highest numbers 
        getReverse(head, rev);

        reverse(rev.begin(), rev.end());

        ListNode *curr = head;
        ListNode *prev = NULL;

        for(int i=0; i<rev.size()-1; i++){
            if(curr == head && rev[i] > curr->val){
                head = curr->next;
                curr->next = NULL;
                prev = NULL;
                curr = head;
            }
            else if(curr != head && rev[i] > curr->val){
                prev->next = curr->next;
                curr->next = NULL;
                curr = prev->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

// Optimized using Recursion
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        // recursively go to last position
        head->next = removeNodes(head->next); 
        // head->next will get next nodes address so when i delete in between the deleted nodes->next is returned 
        // now check for the condition for deletion
        if(head->val < head->next->val){
            // take temp to store nexts nodes addres
            ListNode *temp = head->next;
            return temp; // we returned the address inorder head->next(line:19) will catch it 
        }

        return head;
    }
};