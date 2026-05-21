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

    void getReverse(vector<int>&temp, ListNode *head){
        if(!head){
            return;
        }

        getReverse(temp, head->next);
        temp.push_back(head->val);
    }

    bool isPalindrome(ListNode* head) {
        if(!head->next)
        return true;

        vector<int>temp;
        getReverse(temp, head);

        int start = 0, end = temp.size()-1;
        while(start < end){
            if(temp[start] != temp[end]){
                return false;
            }
            start++, end--;
        }

        return true;
    }
};


// Optimized Solution 
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
        return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *curr = slow;
        ListNode *prev = NULL;

        while(curr){
            ListNode *fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }

        ListNode *start = head;
        ListNode *end = prev;

        while(end){
            if(start->val != end->val)
            return false;

            start = start->next;
            end = end->next;
        }

        return true;
    }
};