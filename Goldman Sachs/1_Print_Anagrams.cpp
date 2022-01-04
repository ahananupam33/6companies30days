#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;

        // Sort the words and store the words in a map
        for(int i=0; i<string_list.size(); i++){
            string s = string_list[i];
            sort(s.begin(), s.end());
            m[s].push_back(string_list[i]);
        }
        for(auto i: m)
            ans.push_back(i.second);
        return ans;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}