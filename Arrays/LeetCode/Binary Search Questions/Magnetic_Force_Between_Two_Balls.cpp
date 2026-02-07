class Solution {
public:

    bool maxMagneticForce(vector<int>arr, int minDistance, int k){
        int count = 1, prev = arr[0];

        for(int i=1; i<arr.size(); i++){
            int curr = arr[i];
            if(curr - prev >= minDistance){
                count++;
                prev = arr[i];
            }
        }

        return count >= k;
    }

    int maxDistance(vector<int>& position, int m) {
        int start=0, ans, n=position.size(), end;
        sort(position.begin(), position.end());

        end = position[n-1] - position[0];

        while(start <= end){
            int mid = start + (end-start)/2;

            if(maxMagneticForce(position, mid, m)){
                ans = mid;
                start = mid + 1;
            }
            else
            end = mid -1;
        }

        return ans;
    }
};