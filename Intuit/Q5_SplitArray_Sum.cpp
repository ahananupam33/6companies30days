class Solution {
public:
    bool solve(vector<int>& nums, int m, int max){
        int chk = 0;
        for(int i=0; i<nums.size(); i++){
            // Single number can't exceed max
            if(nums[i] > max)
                return false;
            // If it is less we add the current number
            else if(chk+nums[i] <= max)
                chk += nums[i];
            else{
                m--;
                chk = nums[i];
                if(m<0)return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        // The max sum will always lie between the largest element and the sum of all elements
        int left = 0, right = 0;
        for(int i=0; i<nums.size(); i++){
            left = max(left, nums[i]);
            right += nums[i];
        }
        
        // Binary Search to find the lower bound for minimum max sum
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (solve(nums, m-1, mid)) 
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};