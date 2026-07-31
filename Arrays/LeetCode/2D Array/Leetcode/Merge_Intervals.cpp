class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int curr = 0;
        
        for(int i=1; i<n; i++){
            if(intervals[i][0] <= ans[curr][1]){
                ans[curr][1] = max(ans[curr][1], intervals[i][1]);
            }
            else{
                curr++;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int curr = 0;
        
        for(int i=1; i<n; i++){
            if(intervals[i][0] <= ans[curr][1]){
                ans[curr][1] = max(ans[curr][1], intervals[i][1]);
            }
            else{
                curr++;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};