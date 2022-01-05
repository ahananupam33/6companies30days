#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution {
	public:
		int CountMsgs(string str, int n){
		    
		    vector<long long int> dp(n+1, 0);
		    dp[0] = 1;
		    dp[1] = 1;
		    if(str[0]=='0')return 0;
		    
		    for(int i=2; i<=n; i++){

                // If last digit is non zero, add to result and check (n-1) digits
		        if(str[i-1] > '0')
		            dp[i] = (dp[i-1]%MOD);
                
                // Check last two digits, if valid then add to result and check (n-2) digits
		        if(str[i-2]=='1' || (str[i-2]=='2' && str[i-1]<'7'))
		            dp[i] = (dp[i]+dp[i-2])%MOD;
		    }
	        return dp[n];
		}
		
		int CountWays(string str){
		    return CountMsgs(str, str.length());
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
} 