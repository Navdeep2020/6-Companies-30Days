int search(int flag, MountainArray mountainArr, int l, int r, int target){
        while(l <= r){
            int mid = (l + r) / 2 ;
            int val = mountainArr.get(mid);
            if(val == target)
                return mid;
            if(flag == val < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // we are going to use binary search

        int l = 0, r = mountainArr.length() - 1;
        while(l < r){
            int mid = (l + r)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid+1))
                r = mid;
            else l = mid + 1;
        } 
        int ans = (search(1,mountainArr,0,l,target));
        if(ans != -1)
          return ans;
        return (search(0,mountainArr,l,mountainArr.length() - 1,target));
    }