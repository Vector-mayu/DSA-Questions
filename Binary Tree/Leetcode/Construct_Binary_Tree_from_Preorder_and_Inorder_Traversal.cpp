class Solution {
public:

    int find(vector<int>&inorder, int start, int end, int &val){
        int index;
        for(int i=start; i<=end; i++){
            if(inorder[i] == val){
                index = i;
                break;
            }
        }
        return index;
    }

    TreeNode *buildTree(vector<int>&preorder, vector<int>&inorder, int start, int end, int &pos){
        // if range dosent match and pos gets out of boud we need to stop
        if(start > end || pos >= preorder.size())
        return NULL;

        TreeNode *temp = new TreeNode(preorder[pos]);
        int val = preorder[pos];

        // here we will check position of val
        // here index will create a partition 
        // left partition = left side of tree
        // right partition = right side of tree
        int index = find(inorder, start, end, val);
        pos++;

        // now find temp->left recursivly using updated start and end
        temp->left = buildTree(preorder, inorder, start, index-1, pos);
        // find temp->right recursivly using updaetd start and end
        temp->right = buildTree(preorder, inorder, index+1, end, pos);

        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        return buildTree(preorder, inorder, 0, inorder.size()-1, pos);
    }
};