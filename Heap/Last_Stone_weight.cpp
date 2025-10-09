class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int>p;

        for(int i=0; i<stones.size(); i++)
        {
            p.push(stones[i]);
        }

        while(p.size()>1)
        {
            int s1 = p.top();
            p.pop();
            int s2 = p.top();
            p.pop();

            if(s1 != s2)
            {
                p.push(s1-s2);
            }
        }

        if(!p.empty())
        return p.top();

        return 0;

    }
};