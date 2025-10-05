// 2558. Take Gifts From the Richest Pile

// PS : You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

// Choose the pile with the maximum number of gifts.
// If there is more than one pile with the maximum number of gifts, choose any.
// Reduce the number of gifts in the pile to the floor of the square root of the original number of gifts in the pile.
// Return the number of gifts remaining after k seconds.


// Approach : Implementation using maxHeap (Priority Queue)


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int>p;

        for(int i=0; i<gifts.size();i++)
        {
            p.push(gifts[i]);
        }

        while(k && !p.empty())
        {
            int g = (int)(sqrt(p.top()));
            p.pop();
            if(g)
            {
                p.push(g);
            }
            k--;
        }

        long long total_gifts = 0;
        while(!p.empty())
        {
            total_gifts += p.top();
            p.pop();
        }
        
        return total_gifts;
    }
};