class Solution {
public:
    int sumOfPrimesInRange(int n) {
        
        string temp = to_string(n);
        reverse(temp.begin(), temp.end());
        int rev = stoi(temp);

        vector<int>primes;
        for(int i = min(n,rev); i<= max(n,rev); i++){
            int isPrime = 1;
            
            if(i <= 1) isPrime = 0;// 0 and 1 case
            
            for(int j=2; j*j<=i; j++){
                if(i % j == 0){
                    isPrime = 0;
                    break;
                }
            }
            if(isPrime)
                primes.push_back(i); 
        }

        int sum = 0;
        for(int i=0; i<primes.size(); i++){
            sum += primes[i];
        }

        return sum;
    }
};