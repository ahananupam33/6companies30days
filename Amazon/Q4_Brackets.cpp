// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string ans = "";
    void printParenthesis(int i, int j, int n, int* bracket, char& name){
        // If only one matrix left in current segment
        if (i == j) {
            ans += (name++);
            return;
        }
    
        ans += "(";
    
        printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);
        printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);
        ans += ")";
    }
    string matrixChainOrder(int p[], int n){
        int dp[n][n], bracket[n][n];
        
        for(int i=1; i<n; i++)
            dp[i][i] = 0;
            
        for(int i=2; i<n; i++){
            for(int j=1; j<n-i+1; j++){
                
                int l = j+i-1;
                dp[j][l] = INT_MAX;
                for(int k=j; k<=l-1; k++){
                     int q = dp[j][k] + dp[k + 1][l] + p[j - 1] * p[k] * p[l];
                     
                     if(q < dp[j][l]){
                         dp[j][l] = q;
                         bracket[j][l] = k;
                     }
                }
            }
        }
        
        char name = 'A';
        printParenthesis(1, n - 1, n, (int*)bracket, name);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends