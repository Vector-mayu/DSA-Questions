int findSubString(string str) {
    // Your code here
    int n = str.length();

    // Sabse Pehle freq calculate karo
    bool freq[256] = {0};
    int uniqueChar = 0;

    for(int i=0; i<n; i++){
        // if its 0 then its coming 1st time -> unique char
        if(freq[str[i]] == 0)
        uniqueChar++;

        freq[str[i]] = 1;
    }

    // Now lets apply Sliding window concept here
    vector<int>count(256, 0);
    int start = 0, end = 0, currUniqueChar = 0, minLen = str.length(); 

    while(end < n){
        // Step1 : Increase the count of specfic character
        count[str[end]]++;

        //Step2 : agar window me koi character pehle barr he aya to -> CUC increase karo
        if(count[str[end]] == 1)
        currUniqueChar++;

        // Step 3 : Agar wohi window me UC aur CUC equal aaye to -> unki length notedown karo
        while(currUniqueChar == uniqueChar){
            // min length ko update karo
            minLen = min(minLen, (end - start)+1);

            // jaise he length update hui window ke size shrink karo aur total count decrease karo
            count[str[start]]--;

            // agar shrink karneke baad unique chars 0 hue to -> CUC ko decrease karo
            if(count[str[start]] == 0)
            currUniqueChar--;

            // shrink the window
            start++;
        }

        // increae the window if all chars are not present in the window
        end++;
    }
    return minLen;
}