#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	// DFS to check which nodes have been visited
	bool dfs(vector<int>& visited, vector<int>adj_v[], int st, int end){
	    if(st==end)return true;
	    visited[st] = 1;
	    for(auto i: adj_v[st]){
	        if(!visited[i]){
	            if(dfs(visited, adj_v, i, end))
	                return true;
	        }
	    }
	    return false;
	}
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> adj_v[V];
        for(int i=0; i<V; i++){
            for(auto j: adj[i]){
                if((i==c and j==d) or (i==d and j==c))
                    continue;
                else
                    adj_v[i].push_back(j);
            }
        }
        
        vector<int> visited(V, 0);
        if(dfs(visited, adj_v, c, d))
            return 0;
        return 1;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}