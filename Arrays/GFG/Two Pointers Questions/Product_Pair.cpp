class Solution {
  public:
    bool isProduct(vector<int> arr, long long x) {
        
        unordered_set<long long> st;
        int n = arr.size();
        int zeroCount = 0;

        // count zeros
        for(long long v : arr){
            if(v == 0) zeroCount++;
        }

        // special case when x == 0
        if(x == 0){
            if(zeroCount >= 2) return true;
            if(zeroCount == 1 && n > 1) return true;
        }

        for(long long v : arr){

            if(v == 0) continue;   // already handled

            if(x % v == 0){
                long long need = x / v;

                if(st.count(need))
                    return true;
            }

            st.insert(v);
        }

        return false;
    }
};
