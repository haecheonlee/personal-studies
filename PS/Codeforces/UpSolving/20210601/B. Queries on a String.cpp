#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	
	int Q; cin >> Q;
	while(Q--) {
		int l, r, k; cin >> l >> r >> k;
		l--, r--;
		int LEN = r - l + 1;
		k %= LEN;
		
		string L = s.substr(l, LEN - k);
		string R = s.substr(l + LEN - k, k);
		string ss = R + L;
		
		for(int i = 0; i < ss.size(); i++) s[i + l] = ss[i];
	}
	cout << s << '\n';
	
	return 0;
}
