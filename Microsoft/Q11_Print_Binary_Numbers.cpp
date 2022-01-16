#include<bits/stdc++.h>
using namespace std;



//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
    queue<int> bin_chk;
    vector<string> ans;
    bin_chk.push(1);
    while(N>0){
        int n = bin_chk.front();
        bin_chk.pop();
        string s = to_string(n);
        ans.push_back(s);
        bin_chk.push(n*10);
        bin_chk.push(n*10+1);
        N--;
    }
    return ans;
	// Your code here
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}