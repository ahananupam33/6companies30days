class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size(), n = isConnected[0].size();
        int ans = 0;
        vector<bool> vis(m, false);
        
        for(int i=0; i<vis.size(); i++){
            ans += !vis[i] ? dfs(isConnected, vis, i), 1 : 0;
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int i){
        vis[i] = true;
        for(int j=0; j<vis.size(); j++){
            if(i != j and isConnected[i][j] and !vis[j])
                dfs(isConnected, vis, j);
        }
    }
};