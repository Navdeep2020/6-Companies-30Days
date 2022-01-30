int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        int n=points.size();
        if(n<3)
            return 0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> mp;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                int xdiff = points[i][0] - points[j][0];
                int ydiff = points[i][1] - points[j][1];
                int dist = pow(xdiff, 2) + pow(ydiff, 2);
                ans += mp[dist];
                mp[dist]++;
            }
        }
        return ans * 2;
    }