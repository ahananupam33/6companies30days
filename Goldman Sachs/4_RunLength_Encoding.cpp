#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}


string encode(string src){     
  string s;
  int count = 1;

  for(int i=1; i<src.length(); i++){
      if(src[i]!=src[i-1]){
          s += src[i-1];
          s += to_string(count);
          count = 1;
      }
      else
        count++;
  }

  // Adds the last group of similar characters
  if(count>0){
      s += src[src.length()-1];
      s += to_string(count);
  }
  return s;
}     
 
