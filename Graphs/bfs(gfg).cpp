vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>visited(V,false); vector<int>bfs;
        
       queue<int>q ;
       q.push(0);
       visited[0] = true; 
       
       while(!q.empty()){
           int u = q.front(); q.pop();
             bfs.push_back(u);
           for(int i=0;i<adj[u].size();i++){
               if(!visited[adj[u][i]]){
                   visited[adj[u][i]]= true;
                   q.push(adj[u][i]);
               }
           }
       }
       
       return bfs;
    }
