class Solution {
public:

    bool PilePossible(vector<int>&arr, int maxSpeed, int k){
        long long totalTime = 0;

        for(int i=0; i<arr.size(); i++){
            totalTime += arr[i]/maxSpeed; // 6/2 = 3 then add 3 in Total Time
            if(arr[i] % maxSpeed) // 7%2 = 1 if reminder exist then increment Total Time
            totalTime++;
        }

        return totalTime <= k;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1, end = 0, ans = 0;

       
        end = *max_element(piles.begin(), piles.end());

        while(start <= end){
            int mid = start + (end - start)/2;

            if(PilePossible(piles, mid, h)){
                ans = mid;
                end = mid -1;
            }
            else
            start = mid + 1;
        }
        return ans;
    }
};