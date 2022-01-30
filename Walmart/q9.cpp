int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = 2; i < n + 1; ++i){
            for(int l=0; l < n - i + 1; ++l){
                
                int r = l + i;
                for(int k = l; k < r; ++k){
                    int ch = k+1;
                    if(k == l){
                        dp[l][r] = ch + dp[l+1][r];
                    } else {
                        dp[l][r] = min(dp[l][r], max(dp[l][k], dp[k+1][r]) + ch);
                    }
                    
                }
            }
        }

        return dp[0][n];
    }