int findpar(int u,vector<int>& par){
        if(u == par[u])
             return u;
        return par[u] = findpar(par[u],par);
    }
   
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> par(n+1);
        for(int i=1;i<n;i++)
            par[i] = i;
            
        int components = n;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                     int u = findpar(i+1,par);
                     int v = findpar(j+1,par);
                    
                     if(u != v){
                         par[v] = u;
                         components--;
                     }
                }
            }
        }
        
      
        return components;
        
    }