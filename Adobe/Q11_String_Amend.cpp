#include<bits/stdc++.h>
using namespace std;



class Solution{
    public:
    string amendSentence (string s)
    {
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i]>='A' and s[i]<='Z'){
                if(i>0)
                    ans += " ";
                s[i] += 32;
            }
            ans += s[i];
            
        }
        return ans;
    }
};


int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}