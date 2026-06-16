// Time Complexity
// As there are 2 nested loops that dosent mean n^2
// here we are visiting each element twice (1. pushing it, 2. accessing the top element and popping if needed)
// do barr se jyada ek element visit hoga he nai dost
TC :- O(2*n)
TC :- O(N)
SC:- O(N) <- stack used 

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n <= k){
            return "0";
        }

        stack<char>st;
        string res = "";

        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(num[i]);
            }
            else{
                while(!st.empty() && k>0 && st.top() > num[i]){
                    st.pop();
                    k--;
                }
                // agar k zero hogya to bhi we will keep pushing
                // and agar while execute bhi hogya then jo next hai woh bhi dala jayega
                // inshort harr element push hoga atleast 1 time
                st.push(num[i]);
            }
        }

        // push everthing into result untill stack is not empty
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        // as its stack we need to reverse it
        reverse(res.begin(), res.end());

        // agar sabh ke sabh incresing order me hue 
        // yani hamne k ko 0 kiya he nai kuch bhi delete kiya he nai phir 
        // 1234 yaha hamara answer starting ke elements he honge kyunki wohi sabhse lowest hai
        // we will pop last k elements then 
        while(res.length() && k>0){
            res.pop_back();
            k--;
        }

        // remove leading zero's
        while(!res.empty() && res[0] == '0'){
            res.erase(0,1);
        }

        //after removing leading zeros if res becamse 0 then?
        if(res.empty())
        return "0";

        return res;
    }
};