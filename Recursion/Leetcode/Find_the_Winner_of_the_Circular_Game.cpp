class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>arr;
        for(int i=1; i<=n; i++){
            arr.push_back(i);
        }

        int i = 0; // jahase counting start hoti hai
        while(arr.size() > 1){
            int index = (i+k-1)%arr.size();

            arr.erase(arr.begin() + index);
            i = index;
        }
        return arr[0];
    }
};