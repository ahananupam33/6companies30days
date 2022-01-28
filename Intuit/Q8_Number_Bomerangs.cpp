class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        
        // Use a hash map to keep track of the boomerang points
        for(int i=0; i<n; i++){
            unordered_map<int, int> m;
            
            // Check the points having same distances
            for(int j=0; j<n; j++){
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int dist = x*x + y*y;
                    
                ans += m[dist]*2;
                m[dist]++;
            }
        }
        return ans;
    }
};