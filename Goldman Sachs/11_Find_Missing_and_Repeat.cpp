#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *ans = new int[2];
        
        for(int i=0; i<n; i++){
            int j = abs(arr[i])-1;
            // Set all new elements as negative
            if(arr[j]>0)
                arr[j] = -1*arr[j];
            // If negative element is encountered it is a repeat
            else
                ans[0] = abs(arr[i]);
        }
        
        // Check for positive element which didn't occur in the array.
        // As per question, there will always be one positive element.
        // That is the missing element.
        for(int i=0; i<n; i++){
            if(arr[i]>0)
                ans[1] = i+1;
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
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}