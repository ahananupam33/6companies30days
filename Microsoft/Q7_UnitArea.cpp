#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    int hor[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int ver[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int RegionSize(vector<vector<int>>& grid, int i, int j){
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())return 0;
        if(!grid[i][j])return 0;
        grid[i][j] = 0;
        return 1 + RegionSize(grid, i - 1, j) 
                 + RegionSize(grid, i + 1, j)
                 + RegionSize(grid, i, j - 1)
                 + RegionSize(grid, i, j + 1)
                 + RegionSize(grid, i - 1,j - 1)
                 + RegionSize(grid, i + 1, j + 1)
                 + RegionSize(grid, i + 1,j - 1)
                 + RegionSize(grid, i - 1,j + 1);
    }
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                maxArea = max(maxArea, RegionSize(grid, i, j));
            }
        }
        return maxArea;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}