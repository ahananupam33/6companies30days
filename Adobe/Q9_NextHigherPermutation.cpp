#include <bits/stdc++.h>
using namespace std;



class Solution{
  public:
    string nextPalin(string N) { 
        int n = N.length();
        if(n <= 3)return "-1";
        
        // We check the next lexicographically higher permutation of the half string
        string h = N.substr(0, n/2);
        if(next_permutation(h.begin(), h.end())){
            string ans = h;
            
            // For odd length, add the middle element to the answer string
            if(n%2 != 0)
                ans += N[n/2];
            
            // Add the last half of string
            reverse(h.begin(), h.end());
            ans += h;
            return ans;
        }
        return "-1";
    }
};


int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}