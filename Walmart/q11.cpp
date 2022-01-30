const int mod = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({efficiency[i],speed[i]});
        }
        
        sort(vp.begin(),vp.end(),greater<pair<int,int>>());
        long long ans = 0,sum = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto &it : vp){
            pq.push(it.second);
            sum += it.second;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            
            ans = max(ans, sum * it.first);
        }
        return ans%mod;
    }