class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), max_v = INT_MIN;
        for(int i=0; i<n; i++)
            max_v = max(max_v, piles[i]);
        
        if(n==h)return max_v;
        int l = 1, r = max_v;
        while(l <= r){
            int mid = (l+r)/2;
            int chk = 0;
            
            for(int i=0; i<n; i++)
                chk += ceil(1.0 * piles[i]/mid);
            if(chk > h)
                l = mid+1;
            else
                r = mid-1;
        }
        return l;
    }
};