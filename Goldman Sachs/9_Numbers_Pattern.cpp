#include<bits/stdc++.h> 
using namespace std; 


class Solution{   
public:
    string printMinNumberForPattern(string S){
        
        stack<int> st;
        string s;
        int val = 1;
        // Stack stores the values and reverses them on popping when I occurs in string
        for(int i=0; i<S.length(); i++){
            st.push(val++);
            
            if(S[i] == 'I'){
                while(!st.empty()){
                    s += to_string(st.top());
                    st.pop();
                }
            }
        }
        
        // Add the remaining stack values to the string
        st.push(val);
        while(!st.empty()){
            s += to_string(st.top());
            st.pop();
        }
        return s;
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 