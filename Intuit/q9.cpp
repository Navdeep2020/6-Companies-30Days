vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    int r = matrix.size();
    if(r == 0) return {};
    int c = matrix[0].size();
    
    vector<vector<int>> ans;
    vector<vector<bool>> p(r, vector<bool>(c, false));
    vector<vector<bool>> a(r, vector<bool>(c, false));
    
    for(int i=0; i<c; i++)
    {
        dfs(matrix, p, INT_MIN, 0, i);
        dfs(matrix, a, INT_MIN, r-1, i);
    }
    
    for(int i=0; i<r; i++)
    {
        dfs(matrix, p, INT_MIN, i, 0);
        dfs(matrix, a, INT_MIN, i, c-1);
    }
    
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(p[i][j] && a[i][j])
                ans.push_back(vector<int> {i,j});
        }
    }
    
    return ans;
}

void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int prev, int i, int j)
{
    if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || prev > matrix[i][j] || visited[i][j]) return;
    
    visited[i][j] = true;
    dfs(matrix, visited, matrix[i][j], i+1, j);
    dfs(matrix, visited, matrix[i][j], i-1, j);
    dfs(matrix, visited, matrix[i][j], i, j+1);
    dfs(matrix, visited, matrix[i][j], i, j-1);
}