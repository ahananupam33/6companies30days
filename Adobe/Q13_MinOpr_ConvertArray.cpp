#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // To store elements of B
        unordered_set<int> s;
        // To store Longest Increasing Subsequence
        vector<int> v;
        for(int i=0; i<M; i++)
            s.insert(B[i]);
            
        for(int i=0; i<N; i++){
            if(s.find(A[i])!=s.end()){
                // Point to the first element just greater than A[i]
                auto itr = lower_bound(v.begin(), v.end(), A[i]);
                
                // Push at the end or insert in between
                if(itr == v.end())
                    v.push_back(A[i]);
                else
                    *itr = A[i];
            }
        }
        
        return (N+M) - (2*v.size());
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}