#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, 
        string str, int m, int n){
            
            if(str.length()==0)return true;
            visited[i][j] = true;
            
            // All 4 possible characters to be checked
            int x[4] = {1, 0, -1, 0};
            int y[4] = {0, -1, 0, 1};
            
            for(int k=0; k<4; k++){
                int xpos = i+x[k];
                int ypos = j+y[k];
                
                // If new position falls outside the board or first character is not found
                if(xpos>=m || xpos<0 || ypos>=n || ypos<0 || board[xpos][ypos]!=str[0])
                    continue;
                
                // If same character found, then apply dfs on substring
                if(board[xpos][ypos]==str[0]){
                    if(!visited[xpos][ypos]){
                        if(dfs(board, visited, xpos, ypos, str.substr(1), m, n))
                            return true;
                    }
                }
            }
            
            visited[i][j] = false;
            return false;
            
        }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0])
                    if(dfs(board, visited, i, j, word.substr(1), m, n))
                        return true;
            }
        }
        return false;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}