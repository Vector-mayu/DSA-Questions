class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, index = 0;

        while(i < n){
            int currChar = chars[i];
            int count = 0;

            // Count total number of repeating characters
            while(i < n && chars[i] == currChar){
                count++;
                i++;
            }

            // Assign the repeating character as currChar 
            chars[index] = currChar;
            index++;

            // if its 10 then push separately as string 10 -> '1' '0'
            if(count > 1){
                string temp = to_string(count);

                for(int j=0; j<temp.length(); j++){
                    chars[index] = temp[j];
                    index++;
                }
            }
        }

        return index;

    }
};