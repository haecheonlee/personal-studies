#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string s,t;
	cin>>s>>t;
	
	while(s.size()<t.size()) {
		int last_index=t.size()-1;
		if(t[last_index]=='A') {
			t.pop_back();
		} else {
			t.pop_back();
			reverse(t.begin(),t.end());
		}
	}

	if(s==t) cout<<1;
	else cout<<0;
	
	return 0;
}

/*
boj.kr/12904

INPUT:
B
ABBA

OUTPUT:
1
*/
