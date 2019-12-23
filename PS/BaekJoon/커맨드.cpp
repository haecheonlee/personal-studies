#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	for(int i=0; i<T; i++) {
		string s;
		cin>>s;
	
		if(s.size() != 7) {
			cout<<0<<endl;
		} else {
			if(s[0] != s[2]) {
				if(s[0] == s[1] && s[1] == s[4] && s[2] == s[3] && s[3] == s[5] && s[5] == s[6]) cout<<1<<endl;
				else cout<<0<<endl;
			} else {
				cout<<0<<endl;
			}
		}
	}

	return 0;
}

/*
boj.kr/17838

INPUT:
1
AABBABB

OUTPUT:
1
*/
