int maxDiff(vector<int> &arr) {
    // Your code here
    int n = arr.size();
	vector<int>SuffixMax(n);
	// Start the SuffixMax calculation from last poistin we need max element onto right side
	SuffixMax[n-1] = arr[n-1];

	//Calculate SuffixMax for all elements
	for(int i=n-2; i>-1; i--){
		SuffixMax[i] = max(arr[i], SuffixMax[i+1]);
	}

	int ans=-1;
	for(int i=0; i<n-1; i++){
		if(arr[i] < SuffixMax[i+1]){
			ans = max(ans, SuffixMax[i+1] - arr[i]);
		}
	}

	return ans;
}