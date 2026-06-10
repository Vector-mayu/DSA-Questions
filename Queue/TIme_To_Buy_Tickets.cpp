// Using queue
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<int>q;

        for(int i=0; i<tickets.size(); i++){
            q.push(i);
        }

        while(!q.empty()){
            // if k ticket is 0
            if(tickets[k] == 0)
            break;
            // if ith man tickets are not 0 then only push again in queue
            if(tickets[q.front()]){
                time++;
                q.push(q.front());
            }
            // after adding total time decrese the tickets count
            tickets[q.front()]--;
            q.pop();
        }
        return time;
    }
};

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int time=0;
        for(int i=0; i<=k; i++)
        {
            time+= min(tickets[k], tickets[i]);
        }
        for(int i=k+1; i<tickets.size(); i++)
        {
            time+= min(tickets[k]-1, tickets[i]);
        }

        return time;
        
    }
};