class Solution {
public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int> st;
        int root = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {

            // Current element cannot be smaller than the
            // minimum allowed value.
            if (arr[i] < root) {
                return false;
            }

            // If we encounter a larger value, we are moving
            // towards the right subtree. Pop all smaller ancestors.
            while (!st.empty() && arr[i] > st.top()) {
                root = st.top();
                st.pop();
            }

            // Store the current node.
            st.push(arr[i]);
        }

        return true;
    }
};  