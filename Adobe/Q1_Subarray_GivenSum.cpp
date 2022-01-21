#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        int c_sum = arr[0],start=0;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            // If sum exceeds target, subtract first number
            while(c_sum>s && start<i-1){
                c_sum-=arr[start];
                start++;
            }
            // If target is obtained, store the indices
            if(c_sum==s){
                ans.push_back(start+1);
                ans.push_back(i);
                return ans;
            }
            if(i<n)
                c_sum+=arr[i];
        }
        ans.push_back(-1);
        return ans;
    }
};


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}