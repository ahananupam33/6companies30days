class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses,vector<int>());
        
        // Stores the courses with prerequisites
        for(auto pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;
        for(int i=0; i<indegree.size(); i++){
            if(!indegree[i])
                q.push(i);
        }
        
        while(!q.empty()){
            int fr = q.front();
            q.pop();
            
            ans.push_back(fr);
            for(auto v: graph[fr]){
                indegree[v]--;
                if(!indegree[v])
                    q.push(v);
            }
        }
        
        if(ans.size() == numCourses)
            return ans;
        else
            return vector<int>();
    }
};