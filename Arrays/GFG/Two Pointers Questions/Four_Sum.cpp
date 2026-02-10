bool find4Numbers(vector<int>& A, int X) {
    int n = A.size();
    sort(A.begin(), A.end());

    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            int sum1 = A[i] + A[j];
            int newTarget = X - sum1;
            int start = j+1, end = n-1;

            while(start < end){
                int sum2 = A[start] + A[end];

                if(sum2 == newTarget)
                return true;
                else if(sum2 > newTarget)
                end--;
                else
                start++;
            }
        }
    }
    return false;
}