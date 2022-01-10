#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(r==0)return 0;
        
        // dir is used to get (-1,0),(0,1),(1,0),(0,-1) bt taking adjacent elements
        vector<int> dir={-1,0,1,0,-1};
        queue<pair<int,int>> q;
        
        // Store coordinates of rotten oranges in a queue
        int fresh = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        //
        int ans = -1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                pair<int,int> p = q.front();
                q.pop();
                // Oranges adjacent to a rotten orange become rotten
                for(int i=0; i<4; i++){
                    int x = p.first + dir[i];
                    int y = p.second + dir[i+1];
                    // Oranges getting rotten are stored in the queue
                    if(x>=0 && x<r && y>=0 && y<c && grid[x][y]==1){
                        grid[x][y] = 2;
                        q.push({x,y});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh>0)return -1;
        if(ans==-1)return 0;
        return ans;
    }
};

int main() {
	int t;
	cin >> t;
	while(t--){
	    int m,n;
	    cin >> m >> n;
	    vector<vector<int>> mat(m, vector<int>(n));
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            cin >> mat[i][j];
	        }
	    }
	    
	    Solution obj;
	    cout << obj.orangesRotting(mat) << endl;
	}
	return 0;
}