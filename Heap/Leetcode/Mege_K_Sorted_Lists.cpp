// Leetcode :- 147. Merge k Sorted Lists

//Companies :- 
// Google
// Amazon
// Microsoft
// Facebook
// Apple
// Netflix
// Uber
// LinkedIn

class Solution {
public:

    class Compare
    {
        public:
        bool operator()(ListNode *a, ListNode *b) // Its like swapping for (sorting) the elements in PQ
        {
            // Conditon for MinHeap
            return a->val > b->val; // In Heap we will use ulta sign '<' ---> '>'
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& arr) {

         int k = arr.size();
        priority_queue< ListNode *, vector< ListNode *>, Compare>p; // here array is whole pushed into PQ 
        
        for(int i=0; i<k; i++)
        {
            if(arr[i] != NULL)
            p.push(arr[i]);
        }
        
        ListNode *root = new ListNode(0); // Dummy node (0)
        ListNode *tail = root; // tail is used for iteration
        
        ListNode *temp;
        
        while(!p.empty())
        {
            // Step 1
            temp = p.top(); // get the top value from PQ
            p.pop();
            
            // Step 2
            tail->next = temp; // Add it in the final ans LL
            tail = tail->next; // Iterate tail ahead
            
            // Step 3 
            if(temp->next) // if kth node contains any nth Node 
            p.push(temp->next); // if yea then push it intp PQ
        }
        
        return root->next;
        
    }
};


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

    struct cmp{
        bool operator()(ListNode *first, ListNode *second){
            return first->val > second->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // 1. Put the first node of every linked list into a min heap.
        // 2. While the heap isn't empty:
        //     a. Take the smallest node.
        //     b. Attach it to the answer.
        //     c. Move forward in that node's original list.
        //     d. Put that next node into the heap.
        // 3. Return the answer.
        
        // min heap
        priority_queue<ListNode*, vector<ListNode*>, cmp>pq;

        for(int i=0; i<lists.size(); i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }

        // actual part of making the final LL
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        while(!pq.empty()){
            ListNode *curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;
            curr = curr->next;

            if(curr){
                pq.push(curr);
            }
        }

        return dummy->next;
    }
};