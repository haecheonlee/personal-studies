#include <iostream>

using namespace std;

int N;
string s[101];

bool is_palindrome(string &p) {
	int len=p.size();
	for(int i=0; i<len/2; i++) {
		if(p[i]!=p[len-i-1]) return false;
	}
	
	return true;
}

string go() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i==j) continue;
			
			string x=s[i]+s[j];
			if(is_palindrome(x)) return x;
		}
	}
	
	return "";
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		cin>>N;
		for(int i=0; i<N; i++) cin>>s[i];

		string ans=go();
		if(ans=="") cout<<0<<'\n';
		else cout<<ans<<'\n';
	}
	return 0;
}
