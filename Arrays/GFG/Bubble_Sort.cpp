class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        // Iteration 1 => 0---n-1 (0-4)
        // Iteration 2 => 0---n-2 (0-3)
        // Iteration 3 => 0---n-3 (0-2)
        // Iteration n => 0---n-1-i
        
        for(int i=0; i<n-1; i++)
        {
            for(int j=0;j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
        }
    }
};