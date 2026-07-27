// TC :- O(N) + O(log(N)) => O(nlogn)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // the approach is to Divide and conquer
        // find middle using slow and fast pointer (floyd tortoise and hare algo)
        // we need to break the LL just before slow node -> create a slow_prev node

        // if head is null
        if(!head){
            return nullptr;
        }

        // if single node
        if(!head->next){
            return new TreeNode(head->val);
        }

        // if earlier conds dosent satisfy we will find middle of LL
        ListNode* slow_prev = nullptr, *slow = head, *fast = head;
        while(fast && fast->next){
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // after getting middle make middle node (slow node)
        TreeNode *root = new TreeNode(slow->val);

        // recursively create left and right 

        // break connection of middle noed and left subtree
        slow_prev->next = nullptr;

        // left 
        root->left = sortedListToBST(head);

        //right 
        root->right = sortedListToBST(slow->next);

        return root;
    }
};