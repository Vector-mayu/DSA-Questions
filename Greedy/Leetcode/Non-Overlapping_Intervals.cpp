class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /// this question is same like n meetings 
        // we will sort them by their end time

        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(),
            [] (const vector<int>&a, const vector<int>&b){
                return a[1] < b[1];
            }
        );

        // this will point the last element with its end time -> so that we can compare according to end time
        int prevEndTime = intervals[0][1];

        // iterate and compare prevEndTime with currents start time inorder to check if its overlapping or not
        int totalMeetings = 1;
        for(int i=1; i<n; i++){
            if(intervals[i][0] >= prevEndTime){
                totalMeetings++;   
                // update end time
                prevEndTime = intervals[i][1];
            }
        }

        return n - totalMeetings;
    }
};