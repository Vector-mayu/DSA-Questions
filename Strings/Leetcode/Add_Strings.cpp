class Solution {
public:
    string addStrings(string num1, string num2) {
        int FirstEnd = num1.size()-1, SecondEnd = num2.size()-1;
        int carry = 0;
        string ans;

        while(FirstEnd >= 0 || SecondEnd >= 0 || carry!=0){
            int sum = carry;

            if(FirstEnd >= 0){
                sum += num1[FirstEnd] - '0';
                FirstEnd--;
            }

            if(SecondEnd >= 0){
                sum += num2[SecondEnd] - '0';
                SecondEnd--;
            }

            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};