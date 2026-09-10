class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        // adjacency list in different notation
        unordered_map<char, vector<char>>adj;
        // inDegree notation using map
        unordered_map<char, int>inDegree;
        
        // lets initialize inDegree elements
        for(auto word : words){
            for(char c : word){
               inDegree[c] = 0; 
            }
        }
        
        // lets create adjacency list
        for(int i=0; i<words.size()-1; i++){
            string first = words[i];
            string second = words[i+1];
            
            int len = min(first.size(), second.size());
            int j = 0;
            
            while(j<len && first[j] == second[j]){
                j++;
            }
            
            // rohitnegi comes before rohit then this dosent obey rule of dict
            // same short word must come before long word in dictionary
            if(j==len && first.size() > second.size())
            return "";
            
            if(j < len){
                char u = first[j];
                char v = second[j];
                
                adj[u].push_back(v);
                inDegree[v]++;
            }
        }
        
        queue<char>q;
            
            // pushing 0 inDegree value elements into into queue
        for(auto &it : inDegree){
            if(it.second == 0){
                q.push(it.first);
            }
        }
        string result;
            
        while(!q.empty()){
            char node = q.front();
            result.push_back(node);
            q.pop();
                
            for(char neib : adj[node]){
                inDegree[neib]--;
                    
                if(!inDegree[neib]){
                    q.push(neib);
                }
            }
        } 
        
        return result.size() != inDegree.size() ? "" : result;
    }
};