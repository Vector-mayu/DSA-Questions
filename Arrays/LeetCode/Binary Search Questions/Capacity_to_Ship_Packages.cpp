// Time Complexity = O(N∗Log(Sum(Weights)))

// Companies :- Netflix, Airbnb, Spotify

class Solution {
public:

    bool ShipmentPossible(vector<int>arr, int maxWeight, int k){
        int days = 1, weight = arr[0];
        for(int i=1; i<arr.size(); i++){
            weight += arr[i];
            if(weight > maxWeight){
                days++;
                weight = arr[i];
            }
        }
        return days <= k;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int start = 0, end = 0, ans = 0;

        if(n < days)
        return -1;

        for(int i=0; i<n; i++){
            start = max(start, weights[i]);
            end += weights[i];
        }

        while(start <= end){
            int mid = start + (end - start)/2;

            if(ShipmentPossible(weights, mid, days)){
                ans = mid;
                end = mid -1;
            }
            else
            start = mid + 1;
        }
        return ans;
    }
};


