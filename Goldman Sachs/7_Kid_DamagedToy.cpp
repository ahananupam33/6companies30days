#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int findPosition(int N , int M , int K) {
        
        int pos = (K+M-1);
        
        // If the no of items is less than the remaining distance to beginning of circle
        if(M < (N-K+1))
            return pos;
        // For others, we simply check the remainder
        return pos%N==0 ? N : pos%N;
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
}