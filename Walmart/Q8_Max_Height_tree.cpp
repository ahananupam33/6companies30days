#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int height(int N){
        return (-1 + sqrt(1+8*N))/2;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.height(N)<<endl;
    }
    return 0;
}