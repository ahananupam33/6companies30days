#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Ordered map stores strings in lexicographical order
        map<string, int> m;
        vector<string> ans;
        
        // Store the candidates with votes in ordered map
        for(int i=0; i<n; i++)
            m[arr[i]]++;
        
        // We find the max voted candidate
        int max_v = 0;
        string candidate;
        for(auto itr: m){
            if(itr.second > max_v){
                max_v = itr.second;
                candidate = itr.first;
            }
        }
        
        ans.push_back(candidate);
        ans.push_back(to_string(max_v));
        return ans;
    }
};


int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}