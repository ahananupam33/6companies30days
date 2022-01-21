#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++)
            sum += arr[i];
        // Odd sum can't be divided to equal parts
        if(sum%2 != 0)return 0;
        
        vector<vector<bool>> dp(N+1, vector<bool>(sum+1));
        
        // 0 sum can be partitioned in any way
        for(int i=0; i<=N; i++)
            dp[i][0] = true;
        // Finite sum with 0 elements is impossible
        for(int i=1; i<=sum; i++)
            dp[0][i] = false;
            
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                // Either include the element in partition or exclude it
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        if(dp[N][sum/2])return 1;
        return 0;
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}