#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}


/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        vector<int> ans;
        
        int max_sofar = arr[0];
        int prv = arr[0], curr = -1, next = -1;
        for(int i=0; i<N; i++){
            // All 3 elements have been found
            if(curr!=-1 && next!=-1)
                break;
            else if(arr[i] < prv && curr==-1)
                prv = arr[i];
            else if(arr[i] > prv && curr==-1)
                curr = arr[i];
            else if(arr[i] > prv && arr[i] < curr)
                curr = arr[i];
            else if(arr[i] > curr && curr > -1 && next==-1)
                next = arr[i];
        }
        if(curr!=-1 && next!=-1){
            ans.push_back(prv);
            ans.push_back(curr);
            ans.push_back(next);
        }
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}