long long power(long long N,long long R)
    {
       
       long long x = 1;
       
       while(R > 0){
           if(R%2 == 0){
               N = (N * N)%mod;
               R /= 2;
           }
           else{
               x = (x * N)%mod;
               R--;
           }
           
       }
       
       return x;
        
    }