bool dfs(vector<vector<char>>& board, string word, int i, int j, int idx){
        if(i < 0 || j < 0 || i > board.size() -1 || j > board[0].size() - 1)
           return false;

        if(idx == word.size())
             return true;

        if(word[idx] == board[i][j]){
            char temp = board[i][j];
            board[i][j] = '0';

            bool t = dfs(board, word, i - 1, j, idx + 1);
            bool d = dfs(board, word, i + 1, j, idx + 1);
            bool l = dfs(board, word, i, j - 1, idx + 1);
            bool r = dfs(board, word, i, j + 1, idx + 1);

            board[i][j] = temp;

            return t || d || l || r;
        }
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int k = 0,n = board.size(),m = board[0].size();
        bool ans = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    ans = dfs(board,word,i,j,0);

                    if(ans)
                      return ans;
                }
            }
        }
        return false;
    }