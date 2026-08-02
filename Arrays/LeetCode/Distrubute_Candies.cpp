class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());

        int n = candyType.size();
        int curr = candyType[0];
        int type = 1;

        for(int i=1; i<n; i++){
            if(curr != candyType[i]){
                type++;
                curr = candyType[i];
            }
        }

        return min(n/2, type);
    }
};