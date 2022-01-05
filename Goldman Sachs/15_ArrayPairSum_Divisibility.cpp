#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int sum = 0, n = nums.size();
        
        // Odd length arrays can't form pairs
        if(n%2!=0)return false;
        
        // Store the remainders in an unordered map
        unordered_map<int, int> m;
        for(int i=0; i<n; i++)
            m[nums[i]%k]++;
            
        for(int i=0; i<n; i++){
            int r = nums[i]%k;
            // If remainder is 0 or divides k into 2 halves, it should occur even times
            if(r==0 || 2*r == k){
                if(m[r]%2 != 0)return false;
            }
            // FOr other cases, r and k-r must occur equal times
            else if(m[r]!=m[k-r])return false;
        }
        return true;
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}