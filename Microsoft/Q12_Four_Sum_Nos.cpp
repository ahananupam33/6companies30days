#include <bits/stdc++.h>
using namespace std;


// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        int n = arr.size();
        
        // Sorting the array will reduce complexity
        sort(arr.begin(), arr.end());
        
        // To store the unique quadruples, we use a set
        set<vector<int>> s;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                // For 3rd and 4th elements, we use st and end
                int st = j+1, end = n-1;
                
                // Check all possible quadruples
                while(st < end){
                    int sum = arr[i] + arr[j] + arr[st] + arr[end];
                    if(sum == k){
                        s.insert({arr[i], arr[j], arr[st], arr[end]});
                        st++;
                        end--;
                    }
                    else if(sum < k)
                        st++;
                    else
                        end--;
                }
            }
        }
        
        for(auto itr: s)
            ans.push_back(itr);
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}