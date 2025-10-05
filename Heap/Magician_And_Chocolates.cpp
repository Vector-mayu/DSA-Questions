// // Given N bags, each bag contains Bi chocolates. There is a kid and a magician. 
// In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the 
// magician fills the ith bag with floor(Bi/2) chocolates.

// APPROIACH
// 1 Max Heap for getting a bag with maximum chocolates
// I will choose the max bag and eat all chocolates in 1 unit time [A]
// Then we will push n/2 chocolates into max heap again 
// atlast will return the maximum chocolates eaten by the kid


// Implementation

int Solution::nchoc(int A, vector<int> &B) {
    
    
    priority_queue<int>p;
    
    for(int i=0; i<B.size(); i++)
    {
        p.push(B[i]);
    }
    
    long long maxChocolates = 0;
    
    while(A && !p.empty())
    {
        maxChocolates += p.top();
        
        if(p.top()/2)
        {
            p.push(p.top()/2);
        }
        
        p.pop();
        A--;
    }
    
    return maxChocolates % 1000000007;    
}

// Time Complexity : O(n+A⋅log(n+A)) -> Alogn 
// Space Complexity : O(n+A)

