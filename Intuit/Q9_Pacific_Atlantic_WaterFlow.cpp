class Solution {
public:
    // We check if water can reach Atlantic and Pacific separately
    vector<vector<bool>> pacific, atlantic;
    vector<vector<int>> ans;    
    int m,n;
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(!size(heights))return ans;
        m = size(heights), n = size(heights[0]);
        pacific = atlantic = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) 
            dfs(heights, pacific, i, 0), dfs(heights, atlantic, i, n - 1);
        for(int i = 0; i < n; i++) 
            dfs(heights, pacific, 0, i), dfs(heights, atlantic, m - 1, i);             
        return ans;

    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool> >& vis, int i, int j){
        if(vis[i][j])return;
        vis[i][j] = true;
        
        if(atlantic[i][j] && pacific[i][j])ans.push_back(vector<int>{i,j});
        
        if(i + 1 <  m && heights[i + 1][j] >= heights[i][j]) dfs(heights, vis, i + 1, j); 
        if(i - 1 >= 0 && heights[i - 1][j] >= heights[i][j]) dfs(heights, vis, i - 1, j);
        if(j + 1 <  n && heights[i][j + 1] >= heights[i][j]) dfs(heights, vis, i, j + 1); 
        if(j - 1 >= 0 && heights[i][j - 1] >= heights[i][j]) dfs(heights, vis, i, j - 1);
        
    }
};