#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> maxNumbers(vector<int>& arr){
        vector<int> ans;
        
        // Priority queue will store the 10 largest numbers
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0; i<arr.size(); i++){
            q.push(arr[i]);
            // If size exceeds 10, the lowest number is popped
            if(q.size() > 10)q.pop();
        }
        
        while(!q.empty()){
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        
        Solution obj;
        vector<int> ans = obj.maxNumbers(arr);
        for(int i=9; i>=0; i--)
            cout << ans[i] << " ";
        cout << endl;
    }
}