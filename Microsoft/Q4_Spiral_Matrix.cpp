#include <bits/stdc++.h> 
using namespace std; 


class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        
        int top = 0, down = (r-1), left = 0, right = (c-1);
        int i = 0;
        while(top<=down && left<=right){
            // Mpve right
            if(i==0){
                for(int j=left; j<=right; j++)
                    ans.push_back(matrix[top][j]);
                top++;
            }
            // Move down
            else if(i==1){
                for(int j=top; j<=down; j++)
                    ans.push_back(matrix[j][right]);
                right--;
            }
            // Move left
            else if(i==2){
                for(int j=right; j>=left; j--)
                    ans.push_back(matrix[down][j]);
                down--;
            }
            // Move up
            else if(i==3){
                for(int j=down; j>=top; j--)
                    ans.push_back(matrix[j][left]);
                left++;
            }
            i = (i+1)%4;
        }
        return ans;
        
    }
};


int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}