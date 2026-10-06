int findParent(int u, vector<int>&parent){
    // ultimate parent got
    if(u == parent[u]){
        return u;
    }

    return parent[u] = findParent(parent[u], parent);
}

void findUnion(int u, int v, vector<int>&parent, vector<int>&rank){
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    if(rank[pu] > rank[pv]){
        parent[pv] = pu;
    }
    else if(rank[pu] < rank[pv]){
        parent[pu] = pv;
    }
    else{
        parent[pv] = pu;
        rank[pu]++;
    }
}

int kruskalsMST(int V, vector<vector<int>>& edges) {
    vector<int>parent(V);
    for(int i=0; i<V; i++){
        parent[i] = i;
    }
    vector<int>rank(V, 0);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        pq.push({w, {u, v}});
    }

    int cost = 0;
    while(!pq.empty()){
        int w = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        // if both have different parent then only connect an edge
        if(findParent(u, parent) != findParent(v, parent)){
            // if yes then only make connection 
            findUnion(u, v, parent, rank);
            cost += w;
        }
    }

    return cost;
}