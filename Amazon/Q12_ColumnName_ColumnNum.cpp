#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    string colName (long long int n)
    {
        string ans = "";
        stack<char> st;
        
        // This gives us the string in reverse which we push into a stack
        while(n>0){
            int r = (n-1)%26;
            st.push((char)(r + 'A'));
            n = (n-1)/26;
        }
        
        // To get the correct string we reverse the string using a stack
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};


int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
