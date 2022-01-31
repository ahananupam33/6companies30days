class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        return minmoney(dp, 1, n);
    }
    
    int minmoney(vector<vector<int>>& dp, int l, int r){
        if(l >= r)return 0;
        // Memoization
        if(dp[l][r]!=0)return dp[l][r];
        
        int ans = INT_MAX;
        for(int i=l; i<=r; i++){
            int temp = i+max(minmoney(dp, l, i-1), minmoney(dp, i+1, r));
            ans = min(ans, temp);
        }
        dp[l][r] = ans;
        return ans;
    }
};