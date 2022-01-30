void recur(int r, int c, int i, int j, int &ans){
        if(i == r && j == c)
           ans++;

        if(i > r || j > c)
          return;

        recur(r,c,i+1,j,ans);
        recur(r,c,i,j+1,ans);
    } 
    int NumberOfPath(int a, int b)
    {
        int ans = 0;
        recur(a,b,1,1,ans);

        return ans;
    }