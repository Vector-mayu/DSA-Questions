// TC = O(n + nlogn)

class Solution {
  public:
  
  bool AllocateBook(vector<int>&arr, int k, int maxPage){
      int count = 1, pages = arr[0];
      
      for(int i=1; i<arr.size(); i++){
          pages += arr[i];
          
          if(pages > maxPage){
            count++;
            pages = arr[i];
          }
      }
      
      return count <= k;
  }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int start = 0, end = 0, mid;
        
        if(k > n)
        return -1;
        
        // Find the max value in that array
        for(int i=0; i<n; i++){
            start = max(start, arr[i]);
            end += arr[i];
        }
        
        int ans = -1;
        
        while(start <= end){
            
            mid = start + (end - start)/2;
            
            if(AllocateBook(arr,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid +1;
            }
        }
        return ans;
    }
};