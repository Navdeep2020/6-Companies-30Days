 double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double,int>> pq;
        vector<pair<int,double>> graph[n];
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        pq.push({1,start});
        vector<double> finalProb(n,0);

        while(!pq.empty()){
            int point = pq.top().second;
            double prob = pq.top().first;
            pq.pop();

            for(auto child : graph[point]){
                if(child.second*prob > finalProb[child.first]){
                    finalProb[child.first] = child.second*prob;
                    pq.push({finalProb[child.first],child.first});
                }
            }
        }

        return finalProb[end];
    }