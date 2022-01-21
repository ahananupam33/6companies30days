#include <bits/stdc++.h>
using namespace std;


class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n==1)return 1;    
        
        // The dp matrix stores the differences for the respective index values
        vector<vector<int>> dp(n, vector<int>(10000));
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int diff = A[j] - A[i];
                // There need to be at least 2 elements in AP
                dp[j][diff] = max(dp[i][diff]+1, 2);
                ans = max(ans, dp[j][diff]);
            }
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}