#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        // Check for single element array
        if(n==1)
            return a[0]<k ? 1 : 0;
        
        long long run_prod = 1;
        int ans = 0, j=0;
        
        // Find the running product and check in each iteration
        for(int i=0; i<n; i++){
            run_prod *= a[i];
            if(run_prod < k)
                ans += (i-j+1);
            else{
                while(j<i && run_prod>0){
                    run_prod/=a[j];
                    j++;
                    if(run_prod < k){
                        ans += (i-j+1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}