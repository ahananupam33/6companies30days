#include <bits/stdc++.h>
using namespace std;


class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0; i<n; i++)
	        sum += arr[i];
	    
	    bool dp[n+1][sum+1];
	    
	    // 0 sum is possible with all elements
	    for(int i=0; i<=n; i++)
	        dp[i][0] = true;
	    // With 0 elements, only 0 sum is possible
	    for(int i=1; i<=sum; i++)
	        dp[0][i] = false;
	        
	        
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=sum; j++){
	            
	            // If ith element is included
	            if(arr[i-1] <= j)
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            else
	                // Don't include ith element
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    
	    int diff = INT_MAX;
	    for(int i=0; i<=sum/2; i++){
	        if(dp[n][i] && diff > abs(i-(sum-i)))
	            diff = abs(i-(sum-i));
	    }
	    return diff;
	} 
};



int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}