// Same solution as Question 6 (Max. Subarray)

#include <bits/stdc++.h>
using namespace std;


class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        deque<int> dq(k);
        int i;
        
        // Store the index of the max value among the first k elements in deque
        for(i=0; i<k; i++){
            while((!dq.empty()) && arr[i]>=arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        
        // Find max value of each subarray and store in array
        // ELement at front of sorted dequeue is the largest
        for(; i<n; i++){
            // Push largest element in current subarray
            ans.push_back(arr[dq.front()]);
            while((!dq.empty()) && dq.front()<=i-k)
                dq.pop_front();
            // Remove elements smaller than newly added element
            while((!dq.empty()) && arr[i]>=arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        // Add the last subarray's largest element
        ans.push_back(arr[dq.front()]);
        return ans;
    }
};


int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}