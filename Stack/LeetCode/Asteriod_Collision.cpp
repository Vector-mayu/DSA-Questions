class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;

        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                int sum = asteroids[i] + st.top();

                if(sum < 0){
                    st.pop();
                }
                else if(sum > 0){
                    asteroids[i] = 0; // we mark it zero so that we can break this condition as we dont need to do anything
                }
                else{
                    asteroids[i] = 0;
                    st.pop();
                }
            }

            // here we will push
            // push will only happen when
            // case 1 : ith element is positive or sum is negative
            if(asteroids[i] != 0){
                st.push(asteroids[i]);
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};