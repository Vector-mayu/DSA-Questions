class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        
        long long int total = 0; 
        
        unordered_map<long long int, long long int>m;
        m[0]=1; // Intialize the map with ('0'->1)
        
        long long PrefixSum = 0;
        
        for(int i=0;i<arr.size();i++)
        {
            // Aate the Add kardo
            PrefixSum+= arr[i];
            
            if(m.count(PrefixSum)) // if number is repeated
            {
                total+= m[PrefixSum]; // add count of repeatition of number  
                m[PrefixSum]++; // increase the count
            }
            else // if number is not repeated
            {
                m[PrefixSum] = 1; // map me Prefixsum banao and assign count = 1
            }
        }
        
        return total;
        
    }
};