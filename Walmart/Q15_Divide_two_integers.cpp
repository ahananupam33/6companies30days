class Solution {
public:
    int divide(int dividend, int divisor) {
        // One corner case
        if(dividend==INT_MIN && divisor==-1)return INT_MAX;
        
        long long int dvd = abs(dividend), dvs = abs(divisor);
        long long int ans = 0, i = 0;
        while(dvd>=dvs){
            for(i=0; dvd-(dvs << i << 1) >= 0; i++);
            ans += 1 << i;
            dvd -= dvs << i;
        }
        return (dividend>0)==(divisor>0) ? ans : ans*-1;
    }
};