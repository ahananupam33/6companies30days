#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if(n==0)
            return 0;
        if(n==1)
            return arr[0];
        if(n==2)
            return max(arr[0],arr[1]);
        int dp[n+1];
        dp[1] = arr[0];
        dp[2] = max(arr[0],arr[1]);
        
        // Either select the current element or the previous one
        for(int i=3; i<=n; i++)
            dp[i] = max(dp[i-2]+arr[i-1], dp[i-1]);
        return dp[n];
        // Your code here
    }
};


int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}