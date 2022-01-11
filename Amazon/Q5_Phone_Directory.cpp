#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        unordered_set<string> set;
        for(int i=0; i<n; i++){
            set.insert(contact[i]);
        }
        vector<string> contacts(set.size());
        for(auto i: set){
            contacts.push_back(i);
        }
        
        sort(contacts.begin(), contacts.end());
        vector<vector<string>> result(s.length());
        
        for(auto cont:contacts){
            for(int i=0; i<cont.length(); i++){
                if(i<s.length() && s[i]==cont[i])
                    result[i].push_back(cont);
                else
                    break;
            }
        }
        for(int i=0; i<s.length(); i++){
            if(result[i].size()==0)
                result[i].push_back("0");
        }
        return result;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}