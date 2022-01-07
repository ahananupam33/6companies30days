#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        int ans = 0;
        // profit[k][n] shows profit upto nth day after k transactions at most.
        vector<vector<int>> profit(K+1, vector<int>(N+1));
        
        // Base Case: Profit is 0 when there are 0 transactions or on the 0th day.
        for(int i=0; i<=K; i++)profit[i][0] = 0;
        for(int j=0; j<=N; j++)profit[0][j] = 0;
        
        
        // Using dp, we calculate the max profit      
        for(int i=1; i<=K; i++){
            int pre_profit = INT_MIN;
            for(int j=1; j<N; j++){
                pre_profit = max(pre_profit, profit[i-1][j-1] - A[j-1]);
                // Max profit either if there is no transaction on jth day or add to previous profit.
                profit[i][j] = max(profit[i][j-1], pre_profit+A[j]);
                
            }
        }
        return profit[K][N-1];
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}