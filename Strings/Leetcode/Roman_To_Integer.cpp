class Solution {
public:

    int calculateValue(char c){
        string roman = "IVXLCDM";
        int values[] = {1, 5, 10, 50, 100, 500, 1000};

        for(int i=0; i<7; i++){
            if(c == roman[i]){
                return values[i];
            }
        }
        return 0;
    }

    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;

        //N-1 because the last number always gets added by default as it dont have n+1 position to check
        for(int i = 0; i < n-1; i++){
            int curr = calculateValue(s[i]);
            int next = calculateValue(s[i+1]);

            //Substraction if i is lesser than i+1
            if(curr < next){
                ans -= curr; 
            }
            // Addiion if i is not lesser than i+1
            else{
                ans += curr;
            }
        }

        // Added the last value in here
        ans += calculateValue(s[n-1]);

        return ans;
    }
};