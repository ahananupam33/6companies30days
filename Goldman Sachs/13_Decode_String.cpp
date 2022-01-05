#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    string decodedString(string s){
        string ans = "";
        stack<int> int_st;
        stack<char> char_st;
        
        for(int i=0; i<s.length(); i++){
            
            // Checking the numbers and storing them in integer stack
            int count = 0;
            if(s[i]>='0' && s[i]<='9'){
                while(s[i]>='0' && s[i]<='9'){
                    count = (count*10)+(s[i]-'0');
                    i++;
                }
                int_st.push(count);
                i--;
            }
            // Push [ into stack
            else if(s[i]=='['){
                char_st.push(s[i]);
                if(!(s[i-1]>='0' && s[i-1]<='9'))
                    int_st.push(1);
            }
            // Pop all elements until the next [
            else if(s[i]==']'){
                count = 0;
                string temp = "";
                if(!int_st.empty()){
                    count = int_st.top();
                    int_st.pop();
                }
                while(!char_st.empty() && char_st.top()!='['){
                    temp = char_st.top() + temp;
                    char_st.pop();
                }
                if(!char_st.empty() && char_st.top()=='[')
                    char_st.pop();
                
                for(int j=0; j<count; j++)
                    ans = ans + temp;
                for(int j=0; j<ans.length(); j++)
                    char_st.push(ans[j]);
                ans = "";
                
            }
            // If it is a character push unto character stack
            else{
                char_st.push(s[i]);
            }
        }
        while(!char_st.empty()){
            ans = char_st.top() + ans;
            char_st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends