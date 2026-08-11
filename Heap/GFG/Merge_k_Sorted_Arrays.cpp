class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        
        for(int i=0; i<n; i++){
            pq.push({mat[i][0], {i, 0}});
        }
        
        vector<int>ans;
        while(!pq.empty()){
            pair<int, pair<int, int>>temp = pq.top();
            int row = temp.second.first;
            int col = temp.second.second;
            pq.pop();
            
            ans.push_back(temp.first);
            
            if(col < m-1){
                pq.push({mat[row][col+1], {row, col+1}});
            }
        }
        
        return ans;
    }
};