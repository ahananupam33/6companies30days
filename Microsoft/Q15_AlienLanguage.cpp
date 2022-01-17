#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    void solve(int src, vector<int>& vis, vector<int>& top, vector<int> adj_v[]){
        vis[src] = 1;
        for(auto i: adj_v[src]){
            if(!vis[i])
                solve(i, vis, top, adj_v);
        }
        top.push_back(src);
    }
    
    string findOrder(string dict[], int N, int K) {
        
        // Create the adjacency vector by comparing strings
        vector<int>adj_v[K];
        for(int i=1; i<N; i++){
            string a = dict[i-1], b = dict[i];
            
            for(int j=0; j<min(a.size(), b.size()); j++){
                if(a[j]!=b[j]){
                    adj_v[a[j]-'a'].push_back(b[j]-'a');
                    break;
                }
            }
        }
        
        // Topological sorting
        vector<int> vis(K, 0), top;
        for(int i=0; i<K; i++){
            if(!vis[i])
                solve(i, vis, top, adj_v);
        }
        
        reverse(top.begin(), top.end());
        string ans = "";
        for(int i=0; i<top.size(); i++)
            ans += top[i] + 'a';
        return ans;
    }
};


string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}