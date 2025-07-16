void kahns( vector<vector<int>>& g,  vector<int>&indeg, vector<int> & topo) {
          int n = indeg.size();
         queue<int> q;
         for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
         }
    
         while(!q.empty()) {
             int cur = q.front();
             topo.push_back(cur);
             q.pop();
    
             for(auto v : g[cur]) {
                indeg[v]--;
                if(indeg[v] == 0) {
                    q.push(v);
                }
             }
         }
    }


    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> g(V);
        vector<int>indeg(V);
        vector<int> topo;
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            g[u].push_back(v);
            indeg[v]++;
        }   
        
        kahns(g, indeg, topo);
        
        return topo;
        
    }
