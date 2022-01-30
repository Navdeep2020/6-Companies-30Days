 int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, m+n));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i > 0 && dp[i-1][j] != m+n) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                }
                if (j > 0 && dp[i][j-1] != m+n) {
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                }
            }
        }
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i < n-1 && dp[i+1][j] != m+n) {
                    dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                }
                if (j < m-1 && dp[i][j+1] != m+n) {
                    dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
                }
                ans = max(ans, dp[i][j]);
            }
        }
                
        if (ans == 0 || ans == m+n)
            return -1;
        return ans;
    }