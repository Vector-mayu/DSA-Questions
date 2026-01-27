class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int fin = 0, count=0;
        int max = arr[n-1];
        vector<int>ans(max + k + 1, 0);

        for(int i=0; i<n; i++){
            ans[arr[i]]++;
        }

        for(int i=0; i<ans.size(); i++){
            if(ans[i] == 0 && count <= k){
                count++;
                fin = i;
            }
        }
        return fin;
    }
};