#include<iostream>
using namespace std;

int findSum(int arr[], int i, int n, int &ans){
    // base case
    if(i == n)
    return 0;
    
    ans += arr[i] + findSum(arr, i+1, n, ans);
    return ans;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int ans = findSum(arr, 0, 7, 0)
    cout<<ans;
    return 0;
}