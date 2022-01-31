class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});   
        }
        
        vector<int> vis(n, 0);
        priority_queue<pair<double,int>> q;
        // Probability of being at start node is 100%
        q.push({(double)1.0, start});
        
        vector<double> prob(n, 0.0);
        prob[start] = 1.0;
        
        while(!q.empty()){
            double pr = q.top().first;
            int node = q.top().second;
            q.pop();
            
            if(!vis[node]){
                vis[node]++;
                for(auto &x: graph[node]){
                    if(prob[x.first] < x.second * pr){
                        prob[x.first] = x.second * pr;
                        q.push({prob[x.first], x.first});
                    }
                }
            }
        }
        return prob[end];
    }
};