int check(int n, vector<int>& weights,int mid,int days){
         int d = 1, sum = 0;
            for(int i=0;i<n;i++){ 
                  if(sum + weights[i] > mid){
                    d++;
                    sum = 0;
                }
                    sum += weights[i];
            }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end()), h = accumulate(weights.begin(),weights.end(),0)+1;
        int n = weights.size();

        while(l <= h){
            int mid = (l+h)/2;

           int x = check(n,weights,mid,days);

                if(x <= days)
                    h = mid-1;
                else
                    l = mid+1; 
        }

        return l;
    }