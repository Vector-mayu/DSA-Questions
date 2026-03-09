class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>Rmax(n,0); // Suffix Max
        int Lmax = height[0]; // Prefix Max 

        // Intialize Suffix Max with last integer
        Rmax[n-1] = height[n-1];

        // find Suffix max
        for(int i=n-2; i>0; i--){
            Rmax[i] += max(Rmax[i+1], height[i]);
        }

        // Find LeftMax on the the go with answer
        int totalWater = 0;

        for(int i=1; i<n-1; i++){
            int LRmin = min(Lmax, Rmax[i+1]);
            if(LRmin > height[i]){
                totalWater += LRmin - height[i];
            }
            Lmax = max(Lmax, height[i]);
        }

        return totalWater;
    }
};

// Optimized O(N) single pass code

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        int Lmax = 0, Rmax = 0;
        int start = 0, end = n-1;

        while(start < end){
            if(height[start] > height[end]){
                if(height[end] < Rmax){
                    totalWater += Rmax - height[end];
                }
                else
                Rmax = height[end];

                end--;
            }
            else{
                if(height[start] < Lmax){
                    totalWater += Lmax - height[start];
                }
                else
                Lmax = height[start];

                start++;
            }
        }
        return totalWater;
    }
};