#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}

int strtoint(string s){
    long long x=0;
    for(int i=0;i<s.size();i++)
      x = x*10 + (s[i]-'0');
    return x;
}


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str){
    int n = str.size();
    for(int i=1; i<=6 and i<str.length(); i++){
        int l=0, cnt=0, flag=0;
        string temp = "";
        int prev = strtoint(str.substr(l,i));
        int num;
        int j=i;
        while(j < str.length()){
            temp = temp + str[j];
            j++;
            
            if(prev+1 == strtoint(temp)){
                prev = strtoint(temp);
                temp = "";
            }
            else if(prev+2 == strtoint(temp)){
                cnt++;
                num = prev+1;
                prev = strtoint(temp);
                temp = "";
            }
            else if(prev < strtoint(temp))
                flag = 1;
        
        }
        if(cnt==1 && !flag)return num;
    }
    return -1;
}