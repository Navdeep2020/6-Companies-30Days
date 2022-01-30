string kthLargestNumber(vector<string>& nums, int k) {
        auto comp = [](const string &a,const string &b){
           if(a.size() == b.size())
               return a<b;
            return a.size()<b.size();
        };
        priority_queue<string,vector<string>,decltype(comp)> pq(comp);
        for(int i=0;i<nums.size();i++)
            pq.push(nums[i]);
 
        
        string ans;
        while(k--){
          ans = pq.top();
            pq.pop();
        }
      return ans;
    }