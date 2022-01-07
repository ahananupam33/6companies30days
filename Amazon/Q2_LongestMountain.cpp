#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int len = 0;
        int n = arr.size();
        vector<int> up(n), down(n);
        
        // Check where the value of elements slopes up
        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1])
                up[i] = up[i-1]+1;
        }
        
        // Check where the value of elements slopes down
        for(int i=n-2; i>=0; i--){
            if(arr[i] > arr[i+1])
                down[i] = down[i+1]+1;
            
            // The sum of up and down values gives us max length of mountain
            if(up[i]>0 && down[i]>0)
                len = max(len, up[i]+down[i]+1);
        }
        return len;
    }
};

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> arr(n);
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	    Solution ob;
	    cout << ob.longestMountain(arr) << endl;
	}
	return 0;
}