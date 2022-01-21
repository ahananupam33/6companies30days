#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int n = str.length();
        long long int dec = pow(10,n-1), ans = 0;
        int sign = 1;
        
        for(int i=0; i<n; i++){
            // Checks if the number is negative in the first iteration
            if(str[0] == '-' && sign==1){
                sign = -1;
                dec/=10;
            }
            // Checks if the element of string is a number
            else if(str[i]>='0' && str[i]<='9'){
                long long int dig = dec * (str[i]-'0');
                ans += dig;
                dec/=10;
            }
            // If any other character is present, return -1
            else
                return -1;
        }
        return ans*sign;
    }
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}