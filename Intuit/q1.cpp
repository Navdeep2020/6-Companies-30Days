int minDifference(int arr[], int n)  { 
	    if(n == 1)
	       return arr[0];
	    int sum = accumulate(arr,arr+n,0ll);
	    int sumtot = sum;
	    sum = sum/2;
	    int dp[n+1][sum+1];
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<n+1;i++)
	       dp[i][0] = 1;

	   for(int i=1;i<n+1;i++){
	       for(int j=1;j<sum+1;j++){
	           if(arr[i-1] > j)
	             dp[i][j] = dp[i-1][j];
	           else
	             dp[i][j] = max(dp[i-1][j] , dp[i-1][j-arr[i-1]] );
	       }
	   }


	    int ans = INT_MAX;
	    for(int i=1;i<sum+1;i++){
	        if(dp[n][i] > 0){
	          ans = min(ans,sumtot - 2*i);
	        }
	    }

	    return ans;

	}