class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> arr(n);
        for(int i=0; i<n; i++)
            arr[i] = {efficiency[i], speed[i]};
        
        // Sort in reverse
        sort(rbegin(arr), rend(arr));
        
        long long sum = 0, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto& [eff, sp]: arr){
            pq.emplace(sp);
            sum += sp;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum * eff);
        }
        
        return ans%(int)(1e9+7);
    }
};