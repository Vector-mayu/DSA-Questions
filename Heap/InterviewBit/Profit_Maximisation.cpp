int Solution::solve(vector<int> &A, int B) {
    priority_queue<int>pq(A.begin(), A.end());
    
    int profit = 0;
    while(B){
        profit += pq.top();
        pq.push(pq.top()-1);
        pq.pop();
        B--;
    }
    return profit;
}
