#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        // For 1 column or 1 row only 1 path is possible
        if(a==1|| b==1)
            return 1;
            
        return NumberOfPath(a-1, b) + NumberOfPath(a, b-1);
    }
};


int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}