#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int memoizedDP(vector<vector<int>>& dp, vector<int>&A, int i, int j){
        if(i>j)return dp[i][j] = 0;
        if(i==j)return dp[i][j] = A[i];
        
        // Memoization
        if(dp[i][j]!=-1)return dp[i][j];
        
        int left = min(memoizedDP(dp, A, i+2, j), memoizedDP(dp, A, i+1, j-1)) + A[i];
        int right = min(memoizedDP(dp, A, i+1, j-1), memoizedDP(dp, A, i, j-2)) + A[j];
        return dp[i][j] = max(left, right);
    }

    int maxCoins(vector<int>&A,int n)
    {
	    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	    return memoizedDP(dp, A, 0, n-1);
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
