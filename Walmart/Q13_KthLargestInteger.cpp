class compare {
public:
    bool operator() (string &b, string &a) {
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        priority_queue<string, vector<string>, compare> minheap;
        for(int i=0; i<n; i++){
            minheap.push(nums[i]);
            if(minheap.size() > k)
                minheap.pop();
        }
        return minheap.top();
    }
};