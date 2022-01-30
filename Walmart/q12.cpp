 vector<int> recoverArray(int n, vector<int>& sums) {
       sort(sums.begin(), sums.end()); 
        
        vector<int> ans; 
        while (n--) {
            int diff = sums[1] - sums[0]; 
            unordered_map<int, int> freq; 
            vector<int> unique, notunique; 
            bool on = false; 
            for (auto& it : sums) 
                if (!freq[it]) {
                    unique.push_back(it); 
                    freq[it+diff]++; 
                    if (it == 0) on = true; 
                } else {
                    notunique.push_back(it); 
                    freq[it]--; 
                }
            if (on) {
                ans.push_back(diff); 
                sums = unique; 
            } else {
                ans.push_back(-diff); 
                sums = notunique; 
            }
        }
        return ans;  
    }