const int mx = 7;
int getValue(const string& str, int i, int m)
{
    if (i + m > str.length())
        return -1;
    int value = 0;
    for (int j = 0; j < m; j++)
    {
        int c = str[i + j] - '0';
        value = value * 10 + c;
    }
    return value;
}
int missingNumber(const string& str)
{
    for(int i = 1; i < mx; i++){
        int n = getValue(str,0,i);
        
        if(n == -1)
          break;
          
        int missing = -1;
        bool isValid = true;

        for(int j = i; j < str.size(); j += 1 + log10(n)){

            if(missing == -1 && (getValue(str,j,1 + log10(n+2)) == n+2))
               missing = n+1, n += 2;

            else if(getValue(str,j,1 + log10(n+1)) == n+1)
               n++;

            else{
              isValid = false;
              break;
            }
        }
        if(isValid)
           return missing;
    }
     return -1;
}