void recur(string str, string &ans, int idx, int k){
        if(k == 0)
          return;
          
        char mx = str[idx];
        
        for(int i = idx + 1; i < str.size(); i++){
            if(mx < str[i])
              mx = str[i];
        }
        
        if(mx != str[idx])
           k--;
           
        for(int i = str.length() - 1; i >= idx ; i--){
            if(str[i] == mx){
                swap(str[i],str[idx]);
                if(str.compare(ans) > 0)
                  ans = str;
                  
                  
                recur(str, ans, idx+1, k);
                
                swap(str[i],str[idx]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        string ans = str;
        recur(str,ans,0,k);
        
        return ans;
    }