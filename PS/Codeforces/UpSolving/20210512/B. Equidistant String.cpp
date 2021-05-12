#include <iostream>

using namespace std;

int main() {
	string s, t; cin >> s >> t;
	
	int N = s.size(), cnt = 0;
	for(int i = 0; i < N; i++) if(s[i] != t[i]) cnt++;
	
	if(cnt % 2 == 0) {
		int now = 0;
		for(int i = 0; i < N; i++) {
			if(s[i] != t[i]) {
				if(now) cout << s[i];
				else cout << t[i];
				now ^= 1;
			} else {
				cout << s[i];
			}
		}
	} else {
		cout << "impossible";
	}
	
	return 0;
}
