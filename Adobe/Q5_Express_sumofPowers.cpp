#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007


class Solution{
    public:
    long long numOfWays(int n, int x){
        vector<long long> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        
        for(int i=2; i<=(pow(n, 1.0/x)); i++){
            int curr = pow(i, x);
            for(int j=n; j>=curr; j--)
                dp[j] += dp[j-curr]%MOD;
        }
        return dp[n]%MOD;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}