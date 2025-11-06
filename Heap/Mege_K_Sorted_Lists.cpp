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