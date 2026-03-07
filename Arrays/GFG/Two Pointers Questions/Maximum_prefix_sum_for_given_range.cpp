class Solution {
  public:
    vector<int> maxPrefixes(vector<int>& arr, vector<int>& leftIndex,
                            vector<int>& rightIndex) {
        // code here.
        
        vector<int> final_ans;

        for(int i = 0; i < leftIndex.size(); i++){
            int L = leftIndex[i];
            int R = rightIndex[i];

            int currSum = 0;
            int maxSum = INT_MIN;

            for(int j = L; j <= R; j++){
                currSum += arr[j];
                maxSum = max(maxSum, currSum);
            }

            final_ans.push_back(maxSum);
        }

        return final_ans;
    }
};