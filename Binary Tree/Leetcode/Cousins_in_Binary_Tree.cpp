// TC :- O(N) 
// SC :- O(n/2) ~ O(n)
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);

        // we will store parent node and the level(depth)
        pair<TreeNode*, int> p1 = {nullptr, 0};
        pair<TreeNode*, int> p2 = {nullptr, 0};
        int level = 0;

        // same code as level order traversal
        while(!q.empty()){
            int n = q.size();

            // we will push left and right for each node present in the queue
            for(int i=0; i<n; i++){
                TreeNode *node = q.front();
                // if left exist
                if(node->left){
                    // if current nodes(parent) child(left) is x 
                    if(node->left->val == x){
                        p1 = {node, level + 1};
                    }
                    // if current nodes(parent) child(left) is y
                    if(node->left->val == y){
                        p2 = {node, level + 1};
                    }
                    q.push(node->left);
                }
                // vice versa here
                if(node->right){
                    // if current nodes(parent) child(right) is x
                    if(node->right->val == x){
                        p1 = {node, level+1};
                    }
                    // if current nodes(parent) child(right) is y
                    if(node->right->val == y){
                        p2 = {node, level+1};
                    }
                    q.push(node->right);
                }
                // if we get both guys in for loop itself -> break for loop
                if(p1.first && p2.first){
                    break;
                }
                q.pop();
            }
            // if we get both values break while loop
            if(p1.first && p2.first){
                break;
            }
            level++;
        }

        // return true only if parents are differnt and level is same
        return p1.first != p2.first && p1.second == p2.second;
    }
};