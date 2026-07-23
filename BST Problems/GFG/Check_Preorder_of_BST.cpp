class Solution {
  public:
  
    void buildBST(vector<int>&arr, int minVal, int maxVal, int &index, int n){
        if(index>=n || arr[index] < minVal || arr[index] > maxVal){
            return;
        }
        
        // mimic creation of Tree dont actuall build it 
        int value = arr[index++];
        
        // call left and right with their min max ranges
        buildBST(arr, minVal, value, index, n);
        buildBST(arr, value, maxVal, index, n);
    }
  
    bool canRepresentBST(vector<int> &arr) {
        // code here
        // we will not make tree instead we will just mimic that
        // if the traversal dosent reach till last element then 
        // we can say that its answer is false
        // if we reach the last node successfully that means we can build tree using this preorder
        int index = 0;
        buildBST(arr, INT_MIN, INT_MAX, index, arr.size());
        
        return index>=arr.size();
    }
};