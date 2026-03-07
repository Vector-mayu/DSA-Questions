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