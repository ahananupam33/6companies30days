// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

#define MOD 1000000007
class Solution
{
  public:
    long long int power(long long int x, long long int y, long long int p){
        long long int res = 1;
     
        x = x % p;
     
        if (x == 0)
            return 0;
     
        while (y > 0) {
     
            if (y & 1)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }
    
    int kvowelwords(int N, int K) {
        long long int dp[N+1][K+1];
        memset(dp, 0, sizeof(dp));
        
        long long int ans = 1;
        for (int i = 1; i <= N; i++) {
 
            dp[i][0] = ans * 21;
            dp[i][0] %= MOD;
            ans = dp[i][0];
     
            for (int j = 1; j <= K; j++) {
                // If j>i, no string with length i and vowel j can be formed
                if (j > i)
                    dp[i][j] = 0;
                // j==i, all should be vowels
                else if (j == i) 
                    dp[i][j] = power(5, i, MOD);
                else 
                    dp[i][j] = dp[i - 1][j - 1] * 5;
     
                dp[i][j] %= MOD;
     
                ans += dp[i][j];
                ans %= MOD;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends