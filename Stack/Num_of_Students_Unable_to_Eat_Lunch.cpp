class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& san) {

        int failcount=0;
        queue<int>q;
        for(int i=0; i<s.size(); i++)
        {
            q.push(s[i]);
        }

        int i=0;
        while(!q.empty())
        {
            if(q.front()==san[i])
            {
                q.pop();
                failcount=0;
                i++;
            }
            else
            {
                q.push(q.front());
                q.pop();
                failcount++;
            }

            if(failcount == q.size())
            break;
        }

        return q.size();
        
    }
};