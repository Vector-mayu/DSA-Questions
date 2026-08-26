// Pick exactly k cards from both ends.
// Start with all k from left, then shift one card at a time
// from left → right and keep track of the maximum score.
// This checks all (k + 1) possible combinations.

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int leftSum = 0;
        int rightSum = 0;

        // Initially take all k cards from left
        for(int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        int maxiScore = leftSum;

        int left = k - 1;
        int right = n - 1;

        // Replace left cards one by one with right cards
        for(int i = 0; i < k; i++){

            leftSum -= cardPoints[left];
            left--;

            rightSum += cardPoints[right];
            right--;

            maxiScore = max(maxiScore, leftSum + rightSum);
        }

        return maxiScore;
    }
};