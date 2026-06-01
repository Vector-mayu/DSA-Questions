class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int, int>mp;

        int m = n;
        while(m){
            mp[m%10]++;
            m /= 10;
        }

        long long ans = 0;
        m = n;
        while(m){
            ans += mp[m%10] * (m%10);
            mp[m%10] = 0;
            m /=10;
        }

        return ans;
    }
};