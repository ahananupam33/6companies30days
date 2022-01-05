#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // It can be seen that the number of squares for N*N chessboard is the sum of squares
        // of all numbers from 1 to N.
        // Sum of squares of nos from 1 to N = (N*(N+1)*(2*N+1))/6
        return (N*(N+1)*(2*N+1))/6;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
} 