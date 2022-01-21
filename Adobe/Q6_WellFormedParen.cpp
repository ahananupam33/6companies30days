#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;



// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void countParen(vector<string>& ans, string s, int open, int close){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open != 0){
            string s1 = s;
            s1 += '(';
            countParen(ans, s1, open-1, close);
        }
        if(close > open){
            string s1 = s;
            s1 += ')';
            countParen(ans, s1, open, close-1);
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        string s;
        countParen(ans, s, n, n);
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
}