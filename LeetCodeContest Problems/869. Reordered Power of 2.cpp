class Solution {
public:
 
    int GetCountFormat(int n)
    {
        int num = 0;

        while(n)
        {
            num += pow(10, n%10); // 10^2 = 100 + the whole number
            n /= 10; // 812 = 81 , 2 got out
        }

        return num;
    }

    bool reorderedPowerOf2(int n) {

        int input = GetCountFormat(n);

        for(int i=0; i<=29; i++)
        {
            if(input == GetCountFormat(1 << i)) // Stores power 10^n using bit manipulation
            {
                return true;
            }
        }
        
        return false;
        
    }
};