#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check for different strings which don't have any common divisor
        if(str1+str2 != str2+str1)
            return "";
            
        return str1.substr(0, __gcd(str1.length(), str2.length()));
    }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        string a,b;
        cin >> a >> b;
        string gcd_str;
        Solution ob;
        gcd_str = ob.gcdOfStrings(a, b);

        if(gcd_str=="")
            cout << -1 << endl;
        else    
            cout << gcd_str << endl;
    }
    
}