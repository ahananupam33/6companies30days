class Solution {
public:
    void dfs(int n, vector<int>& sums, vector<int>& ans){
        while(sums.size() > 1){
            int cs = sums.size();
            unordered_map<int, int> m;
            for(auto &i: sums)
                m[i]++;
            
            // Diff between largest two elements
            int diff = sums[cs-1] - sums[cs-2];
            
            // We store the values that are encountered
            vector<int> high, low;
            for(auto &i: sums){
                if(m[i]==0)continue;
                m[i]--;
                m[i+diff]--;
                high.push_back(i);
                low.push_back(i+diff);
            }
            
            int chk = 1;
            for(auto&i: high){
                if(i==0){
                    ans.push_back(diff);
                    sums = high;
                    chk = 0;
                    break;
                }
            }
            if(!chk)
                continue;
            else{
                for(auto &i: low){
                    if(i==0){
                        ans.push_back(-diff);
                        sums = low;
                        break;
                    }
                }
            }
        }
    }
    
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int> ans;
        sort(sums.begin(), sums.end());
        dfs(n, sums, ans);
        return ans;
    }
};