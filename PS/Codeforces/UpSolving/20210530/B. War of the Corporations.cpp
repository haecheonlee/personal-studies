#include <iostream>

using namespace std;

int main() {
	string s, t; cin >> s >> t;
	
	int ans = 0;
	for(int i = 0; i < s.size(); i++) {
		if(t.size() + i - 1 < s.size()) {
			bool matched = 1;
			for(int j = 0; j < t.size(); j++) {
				if(s[i + j] != t[j]) {
					matched = 0;
					break;
				}
			}
			if(matched) {
				i += (t.size() - 1);
				ans++;
			}
		}
	}
	cout << ans << '\n';
	
	return 0;
}
