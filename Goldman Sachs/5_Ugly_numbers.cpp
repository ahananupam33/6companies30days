// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long


class Solution{
public:	
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    vector<ull> dp(n+1);
	    dp[0] = 1;
	    int a2=0, a3=0, a5=0;
	    
		// Every ugly number can be obtained by multiplying a previous ugly number by multiples of 2,3 or 5
	    for(int i=1; i<=n; i++){
	        dp[i] = min(2*dp[a2], min(3*dp[a3], 5*dp[a5]));
	        
	        if(dp[i]==2*dp[a2])a2++;
	        if(dp[i]==3*dp[a3])a3++;
	        if(dp[i]==5*dp[a5])a5++;
	    }
	    return dp[n-1];
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}