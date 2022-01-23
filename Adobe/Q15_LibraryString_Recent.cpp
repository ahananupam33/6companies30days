#include <iostream>
using namespace std;

string moreRecent(string s1, string s2){
    int n1 = s1.length(), n2 = s2.length();
    if(n1 == 0 || n2 == 0)return "Invalid";
    int dots1 = 0, dots2 = 0;
    for(int i=0; i<n1; i++){
        if(s1[i]=='.')dots1++;
        else
            dots1 = 0;
        if(dots1>1)return "Invalid";
    }
    for(int i=0; i<n2; i++){
        if(s2[i]=='.')dots2++;
        else
            dots2 = 0;
        if(dots2>1)return "Invalid";
    }
    
    int i=0, j=0;
    while(i<n1 || j<n2){
        int v1 = 0, v2 = 0;
        
        if(s1[i]=='.')dots1++;
        else
            dots1 = 0;
        if(s2[j]=='.')dots2++;
        else
            dots2 = 0;
        
        while(i<n1 && s1[i]!='.'){
            v1 = v1*10 + (s1[i]-'0');
            i++;
        }
        while(j<n2 && s2[j]!='.'){
            v2 = v2*10 + (s2[j]-'0');
            j++;
        }
        
        if(v1 > v2)return s1;
        if(v2 > v1)return s2;
        i++; j++;
    }
    return "Invalid";
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s1,s2;
	    cin >> s1 >> s2;
	    cout << moreRecent(s1, s2) << endl;
	}
	return 0;
}