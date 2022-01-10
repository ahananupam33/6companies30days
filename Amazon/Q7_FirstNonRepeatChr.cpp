#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    int cnt[26] = {0};
		    queue<int> q;
		    
		    // Queue stores all non repeating occurences of characters
		    for(int i=0; i<A.length(); i++){
		        cnt[A[i]-'a']++;
		        // First non repeating characters
		        if(cnt[A[i]-'a'] == 1)
		            q.push(A[i]);
		        
		        // Pop if repeating element is obtained
		        while(!q.empty() && cnt[q.front()-'a']>1)
		            q.pop();
		        
		        if(q.empty())
		            A[i] = '#';
		        else
		            A[i] = q.front();
		    }
		    return A;
		}

};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}