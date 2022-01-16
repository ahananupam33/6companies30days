#include<bits/stdc++.h>
using namespace std;



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>> st;
       st.push({price[0],1});
       vector<int> ans(n,1);
       
       for(int i=1; i<n; i++){
           int curr = price[i];
           int span = 0;
           
           // Adds up all values which form the span if current day has higher price
           while(!st.empty() && st.top().first <= curr){
               span += st.top().second;
               st.pop();
           }
           ans[i] += span;
           st.push({curr, ans[i]});
       }
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}