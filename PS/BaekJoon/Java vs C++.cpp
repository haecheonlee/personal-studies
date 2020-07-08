#include <iostream>

using namespace std;

int main() {
	string s;
	cin>>s;
	
	bool isCpp=false, isJava=false, error=false;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='_') {
			isCpp=true;
			
			// serial of '-', first letter/last letter is '-' 
			if(s[i+1]=='_' || i==0 || i+1==s.size()) error=true;
		}
		if(s[i]>='A' && s[i]<='Z') {
			isJava=true;
			
			// first letter must be lowercase
			if(i==0) error=true;
		}
	}
	
	string ans="";
	if((isCpp && isJava) || error) {
		ans="Error!";
	} else if(isCpp) {
		for(int i=0; i<s.size(); i++) {
			if(s[i]=='_') {
				ans+=toupper(s[i+1]);
				i++;
			} else {
				ans+=s[i];
			}
		}
	} else if(isJava) {
		for(int i=0; i<s.size(); i++) {
			if(s[i]>='A' && s[i]<='Z') {
				ans+="_";
				ans+=tolower(s[i]);
			} else {
				ans+=s[i];
			}
		}
	} else {
		ans=s;
	}
	
	cout<<ans;
	
	return 0;
}
