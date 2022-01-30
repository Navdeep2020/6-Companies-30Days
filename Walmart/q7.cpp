vector<int> find3Numbers(vector<int> arr, int N) {
        vector<int> ans,v;
        stack<int> st;
        int idx = -1;
        st.push(arr[N-1]);
        
        for(int i=N-2;i>=0;i--){
            while(!st.empty() and st.top() <= arr[i]) st.pop();
            v.push_back(st.size());
            if(st.size() == 2) idx = i;
            st.push(arr[i]);
        }
        
        if(idx == -1) return ans;
        
        int p = arr[idx];
        ans.push_back(arr[idx]);
        
        for(int i=idx+1;i<N;i++)
            if(arr[i] > p) ans.push_back(arr[i]), p = arr[i];
        
        return ans;
    }