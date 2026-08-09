class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        // here we are using min heap and max heap concept
        // left side we have max heap
        // rigth side we have min heap
        
        priority_queue<int>leftMaxHeap;
        priority_queue<int, vector<int>, greater<int>>rightMinHeap;
        
        vector<double>result;
        
        // we willl always keep left max heap 1 greater than right min heap
        for(auto x: arr){
            // if we have left max heap empty or the coming element lesser than top of left max heap
            if(leftMaxHeap.empty() || x < leftMaxHeap.top()){
                leftMaxHeap.push(x);
            }
            // if element is greater than leftmax heap top push right
            else{
                rightMinHeap.push(x);
            }
            
            // now size check
            // case 1: if left heap is leftMaxHeap > rightMaxHeap + 1
            if(leftMaxHeap.size() > rightMinHeap.size() + 1){
                rightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();
            }
            // case 2: if left heap is smaller than right heap
            else if(leftMaxHeap.size() < rightMinHeap.size()){
                leftMaxHeap.push(rightMinHeap.top());
                rightMinHeap.pop();
            }
            
            // we are done with balancing -> answer time now
            // case1 : if both are same
            if(leftMaxHeap.size() == rightMinHeap.size()){
                double ans = leftMaxHeap.top() + rightMinHeap.top();
                ans /= 2;
                result.push_back(ans);
            }
            else if(leftMaxHeap.size() > rightMinHeap.size()){
                double ans = leftMaxHeap.top();
                result.push_back(ans);
            }
        }
        
        return result;
    }
};
