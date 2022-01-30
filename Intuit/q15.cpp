int canEat(vector<int>& piles, int bph, int h){
        int tym = 0;
        for(int i=0;i<piles.size();i++){
           tym += ceil(1.0*piles[i]/bph);
        }
        return (tym <= h);
    }
    int minEatingSpeed(vector<int>& piles, int k) {
        int l = 1,h = 1e9;
        
        while(l < h){
            int mid = (l+h)/2;
            
            if(canEat(piles, mid, k))
                h = mid;
            
            else
                l = mid+1;
        }
        return l;
    }