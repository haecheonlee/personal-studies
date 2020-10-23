#include <iostream>

using namespace std;

int main() {
	int N,K;
	cin>>N>>K;

	string s;
	cin>>s;

	if(K==0) cout<<s;
	else {
		if(N==1) cout<<0;
		else {
			int idx=1;
			if(s[0]!='1') { s[0]='1', K--; }
			
			while(K && idx < s.size()) {
				if(s[idx]=='0') { idx++; continue; } 
				s[idx++] = '0';
				K--;
			}

			cout<<s;
		}
	}

	return 0;
}
