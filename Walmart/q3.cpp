
bool winnerOfGame(string colors) {
        int count_A = 0,count_B = 0,n = colors.size();
        if(n <= 2) return false;
        for(int i = 1; i < n - 1; i++){
            if(colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A'){
                count_A++;
            }
            if(colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B'){
                count_B++;
            }
        }
        return count_A > count_B ? true : false;
    }