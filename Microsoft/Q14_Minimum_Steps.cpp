#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int minSteps(int D){
        int step = 0, stsum = 0;
        
        // We add the steps each time until it is greater than D
        // The subtracted value needs to be divisible by 2 because changing n to -n 
        // means subtracting 2*n
        while(true){
            stsum += step;
            step++;
            
            if(stsum == D || (stsum > D and (stsum-D)%2==0))
                return step-1;
        }
        return 0;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}