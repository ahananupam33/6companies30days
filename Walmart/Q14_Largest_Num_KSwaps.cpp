#include <bits/stdc++.h>
using namespace std;



class Solution
{
    public:
    void stringswap(string& str, string& max, int k, int ind){
        if(k==0)return;
        
        char chr = str[ind];
        // Find the greatest number
        for(int i=ind+1; i<str.length(); i++){
            if(str[i] > chr)
                chr = str[i];
        }
        // Perform swap only if max value is different
        if(chr != str[ind])k--;
        
        for(int i=str.length(); i>=ind; i--){
            // Check from end to find the farthest occuring largest element
            if(str[i] == chr){
                swap(str[i], str[ind]);
                
                // Check if after swapping the number is greater
                if(str.compare(max) > 0)
                    max = str;
                
                // Check by going to next index
                stringswap(str, max, k, ind+1);
                swap(str[i], str[ind]);
            }
        }
        
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       string max = str;
       stringswap(str, max, k, 0);
       return max;
    }
};


int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}