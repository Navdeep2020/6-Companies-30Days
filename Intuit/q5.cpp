int splitArray(vector<int>& arr, int m) {
        int l=0, r=0, mid, n = arr.size();
        for(int i=0;i<n;i++){

			  r += arr[i];
        }
        int sum = r;

        int ans =- 1;
        mid = l + (r-l) / 2;
        while(l <= r){

		if(findSol(mid,arr,n,m)){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid + 1;
		}
		mid = l + (r-l) / 2;
	}
        return ans;
    }
    
    bool findSol(int mid,vector<int>& arr,int n,int m){

	int cnt=1, pages=0;
	for(int i=0;i<n;i++){
		if(pages + arr[i]<=mid){
			pages+=arr[i];
		}
		else{
			cnt++;
			if(cnt > m || arr[i] > mid){
				return false;
			}
			pages=arr[i];
		}
	}
	return true;

    }