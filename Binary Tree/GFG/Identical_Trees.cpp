class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        // code here
        bool left, right;
        
        // if both got zero at same time then they are identical
        if(!r1 && !r2){
            return true;
        }
        // if any of them gets zero means they are not identical man
        else if((!r1 && r2) || (r1 && !r2)){
            return false;
        }
        // if both exists
        else{
            // if they dont match then also return false
            if(r1->data != r2->data){
                return false;
            }
            // if everthing satisfies then only go ahead to check on both sides
            left = isIdentical(r1->left, r2->left);
            right = isIdentical(r1->right, r2->right);
        }
        
        // if both sides are true then return true
        if(left && right)
        return true;
        
        // if any of the sides are false then its not identical atall
        return false;
    }
};