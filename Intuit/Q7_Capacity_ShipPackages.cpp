class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        
        // Left bound is the max value in array and right bound is the sum of all elements
        for(int i=0; i<weights.size(); i++){
            left = max(left, weights[i]);
            right += weights[i];
        }
        
        // Binary search for the correct value
        while(left < right){
            int mid = (left+right)/2;
            int curr = 0, req = 1;
            for(int x: weights){
                if(curr + x > mid){
                    req++;
                    curr = 0;
                }
                curr += x;
            }
            if(req > days)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};