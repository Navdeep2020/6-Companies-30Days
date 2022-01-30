vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> ans;
        // if there is only one course
        if(numCourses == 1){
            return {0};
        }

       vector<int> indeg(numCourses,0); 
        vector<int> adj[numCourses];

        //Adjency list representation of the graph
        for(int i=0;i<prerequisites.size();i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);

        // Calculating Ingedree for each node
        for(int i=0;i<numCourses;i++){
            for(auto it : adj[i])
                indeg[it]++;
        }

        queue<int> q;

        //Pushing those elements in queue whose indegree is 0       
        for(int i=0;i<numCourses;i++){
            if(indeg[i] == 0)
                q.push(i);
        }


        while(!q.empty()){
             int temp = q.front();
	        q.pop();
	       ans.push_back(temp);

	        for(auto it = adj[temp].begin();it!=adj[temp].end();it++){
	            if(indeg[*it] > 0)
	              indeg[*it]--;
	            if(indeg[*it] < 1)
	               q.push(*it);
	        }
        }
        reverse(ans.begin(),ans.end());

        // If size of ans is less than numCourses that means you cannot complete all ther courses
        if(ans.size() < numCourses)
            return {};

       return ans; 
    }