int countSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, right = 0;
    int count = 0;
    long long sum = 0;

    while(right < n){
        sum += arr[right];

        while(sum >= k){
            sum -= arr[left];
            left++;
        }

        count += (right - left + 1);
        right++;
    }

    return count;
}