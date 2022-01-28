class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxRight(n,0);
        
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j]){
                    break;
                }
                else
                    cnt++;
            }
            maxRight[i] = cnt;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(maxRight[i] < n-i-1){
                int j=i;
                while(j<n and maxRight[j]<n-1-i)
                    j++;
                if(j==n) return -1;
                while(i<j)
                {
                    swap(maxRight[j],maxRight[j-1]);
                    ans++;
                    j--;
                }
            }
        }
        return ans;
        
        
    }
};