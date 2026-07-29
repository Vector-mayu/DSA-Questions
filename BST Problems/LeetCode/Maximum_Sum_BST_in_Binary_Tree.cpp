class Solution {
public:

    class Box{
        public:
        bool BST;
        int sum, min, max;

        Box(){
            BST = 1;
            sum = 0;
            min = INT_MAX;
            max = INT_MIN;
        }
    };

    Box *maxSum(TreeNode *root, int &totalSum){
        // base case
        if(!root){
            return new Box();
        }

        // now lets call both left and right
        Box *leftHead = maxSum(root->left, totalSum);
        Box *rightHead = maxSum(root->right, totalSum);

        // if side both exist 
        if(leftHead->BST && rightHead->BST  &&  
        leftHead->max < root->val && rightHead->min > root->val){
            Box *head = new Box();
            if(leftHead->sum && rightHead->sum){
                head->sum = leftHead->sum + rightHead->sum + root->val;
                totalSum = max(head->sum, totalSum);
            }
            else if(leftHead->sum && !rightHead->sum){
                head->sum = leftHead->sum + root->val;
                totalSum = max(head->sum, totalSum);
            }
            else if(!leftHead->sum && rightHead->sum){
                head->sum = rightHead->sum + root->val;
                totalSum = max(head->sum, totalSum);
            }
            else{
                head->sum = root->val;
                totalSum = max(head->sum, totalSum);
            }
            head->min = min(root->val, leftHead->min);
            head->max = max(root->val, rightHead->max);
            return head;
        }
        else{
            leftHead->BST = 0;
            return leftHead;
        }
    }

    int maxSumBST(TreeNode* root) {
        int totalSum = 0;
        maxSum(root, totalSum);
        return totalSum;
    }
};