#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool dfsCycle(int index, vector<bool>& visited, vector<bool>& path, vector<int> adj[]){
        if(!visited[index]){
            visited[index] = true;
            path[index] = true;
            for(auto itr: adj[index]){
                if(!visited[itr] && dfsCycle(itr, visited, path, adj))
                    return true;
                else{
                    if(path[itr])
                        return true;
                }
            }
        }
        path[index] = false;
        return false;
    }
    
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    
	    vector<int> adj_vec[N];
	    for(auto i: prerequisites)
	        adj_vec[i.first].push_back(i.second);
	    
	    vector<bool> visited(N,false), path(N,false);
	    
	    for(int i=0; i<N; i++){
	        if(!visited[i]){
	            if(dfsCycle(i, visited, path, adj_vec))
	                return false;
	        }
	    }
	    
	    return true;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}