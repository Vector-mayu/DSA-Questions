bool isPaintingPossible(int maxPaint, vector<int>&arr, int k){
	int count = 1, paint = arr[0], n = arr.size();

	for(int i = 1; i<n; i++){
		paint += arr[i];
		if(paint > maxPaint){
			count++;
			paint = arr[i];
		}
	}
	return count <= k;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //Write your code here.

    int n = boards.size();
	int start = 0, end = 0, ans = -1;

	for(int i = 0; i<n; i++){
		start = max(start, boards[i]);
		end += boards[i];
	}

	while(start <= end){
		int mid = start + (end - start)/2;
		if(isPaintingPossible(mid, boards, k)){
			ans = mid;
			end = mid - 1;
		}
		else
		start = mid + 1;
	}
	return ans;
}