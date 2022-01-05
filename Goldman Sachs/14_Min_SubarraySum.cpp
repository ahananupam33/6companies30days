#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_len = n+1, sum = 0;
        int i=0, j=0;
        while(i < n){
            sum += nums[i++];
            while(sum >= target){
                min_len = min(min_len, i-j);
                sum -= nums[j++];
            }
        }
        if(min_len == n+1)return 0;
        else
            return min_len;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,target;
        cin >> n >> target;
        vector<int> nums(n);
        for(int i=0; i<n; i++)
            cin >> nums[i];
        
        Solution obj;
        cout << obj.minSubArrayLen(target, nums) << endl;
    }
}