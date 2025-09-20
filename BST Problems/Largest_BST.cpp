// GeeksForGeeks Medium BST Problem (Recursive Approach)

class Box {
public:
    bool BST;
    int size;
    int min;
    int max;

    Box() {
        BST = true;
        size = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

class Solution {
public:
    Box find(Node *root, int &TotalSize) {
        // Base case
        if (!root) {
            return Box();
        }

        // Recursive calls
        Box LeftHead = find(root->left, TotalSize);
        Box RightHead = find(root->right, TotalSize);

        Box head;

        // Check BST conditions
        if (LeftHead.BST && RightHead.BST &&
            (LeftHead.max < root->data) && (RightHead.min > root->data)) {

            head.BST = true;
            head.size = 1 + LeftHead.size + RightHead.size;
            head.min = min(root->data, LeftHead.min);
            head.max = max(root->data, RightHead.max);

            // Update global answer
            TotalSize = max(TotalSize, head.size);
        } 
        else {
            head.BST = false;
            head.size = max(LeftHead.size, RightHead.size); // to continue checking largest size
        }

        return head;
    }

    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        int TotalSize = 0;
        find(root, TotalSize);
        return TotalSize;
    }
};

