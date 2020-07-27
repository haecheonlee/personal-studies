#include <iostream>

using namespace std;

bool go(string &s, int index) {
	if(s.size()==index) return true;
	if(s.size()<index) return false;
	
	if(s[index]=='p' && index+1<s.size()) {
		if(s[index+1]=='i') return go(s, index+2);
	}
	else if(s[index]=='k' && index+1<s.size()) {
		if(s[index+1]=='a') return go(s, index+2);
	}
	else if(s[index]=='c' && index+2<s.size()) {
		if(s[index+1]=='h' && s[index+2]=='u') return go(s, index+3);
	}
	
	return false;
}

int main() {
	string s;
	cin>>s;
	
	if(go(s,0)) cout<<"YES";
	else cout<<"NO";

	return 0;
}
