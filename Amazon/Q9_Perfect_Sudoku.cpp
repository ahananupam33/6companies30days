#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int isValid(vector<vector<int>> mat){
        int flag = true;
        
        // Checking the rows
        for(int i=0; i<9; i++){
            vector<int> bit_row(10,0);
            for(int j=0; j<9; j++){
                if(mat[i][j] != 0){
                    bit_row[mat[i][j]] ^= mat[i][j];
                    if(bit_row[mat[i][j]] == 0)
                        flag = false;
                }
            }
        }
        if(!flag)return 0;
        
        // Checking the columns
        for(int i=0; i<9; i++){
            vector<int> bit_col(10,0);
            for(int j=0; j<9; j++){
                if(mat[j][i] != 0){
                    bit_col[mat[j][i]] ^= mat[j][i];
                    if(bit_col[mat[j][i]] == 0)
                        flag = false;
                }
            }
        }
        if(!flag)return 0;
        
        // Checking the 3*3 squares
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                
                vector<int> bit_box(10,0);
                for(int k=i; k<(i+3); k++){
                    for(int l=j; l<(j+3); l++){
                        if(mat[k][l] != 0){
                            bit_box[mat[k][l]] ^= mat[k][l];
                            if(bit_box[mat[k][l]] == 0)
                                flag = false;
                        }
                    }
                }
            }
        }
        if(!flag)return 0;
        return 1;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}