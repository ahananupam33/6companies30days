class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q1,q2;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // If land is encountered we store adjacent locations in queue
                if(grid[i][j]){
                    q1.push({i-1,j});
                    q1.push({i,j+1});
                    q1.push({i+1,j});
                    q1.push({i,j-1});
                }
            }
        }
        int dist = 0;
        while(!q1.empty()){
            dist++;
            while(!q1.empty()){
                int i = q1.front().first;
                int j = q1.front().second;
                q1.pop();

                if(i>=0 && j>=0 && i<n && j<n && !grid[i][j]){
                    grid[i][j] = dist;
                    q2.push({i-1,j});
                    q2.push({i,j+1});
                    q2.push({i+1,j});
                    q2.push({i,j-1});
                }
            }
            swap(q1, q2);
        }
        return dist==1 ? -1 : dist-1;
    }
};