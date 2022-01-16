#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    // Reverse each row of the matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            swap(matrix[i][j], matrix[i][n-1-j]);
        }
    }
    
    // Take transpose of the matrix
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}


int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
