#include <iostream>

using namespace std;

int main() {
	string s1,s2;
	cin>>s1;
	
	string x="";
	for(auto c : s1) {
		if(c>='0' && c<='9') continue;
		x+=c;
	}
	
	cin>>s2;
	bool ans=false;
	for(int i=0; i<x.size(); i++) {
		if(s2[0]==x[i]) {
			if(i+s2.size()>x.size()) continue;
			string s3=x.substr(i,s2.size());
			
			if(s3==s2) {
				ans=true;
				break;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}
