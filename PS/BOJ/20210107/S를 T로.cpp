#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for(int tc = 1; tc <= T; tc++) {
		string s, t;
		cin >> s >> t;

		int t0 = 0, t1 = 0;
		for(int i = 0; i < (int)t.size(); i++) {
			if(t[i] == '0') t0++; else t1++;		
		}
		
		int s0 = 0, s1 = 0;
		for(int i = 0; i < (int)s.size(); i++) {
			if(s[i] == '0') s0++; else if(s[i] == '1') s1++;
		}
		
		int ans = 0;
		for(int i = 0; i < (int)s.size(); i++) {
			if(s[i] == '?') {
				if(t[i] == '0') {
					if(s0 < t0) s0++, s[i] = '0';
					else s1++, s[i] = '1';
				} else if(t[i] == '1') {
					if(s1 < t1) s1++, s[i] = '1';
					else s0++, s[i] = '0';
				}
				
				ans++;
			}
		}
		
		if(s0 < t0) {
			ans = -1;
		} else {
			if(s0 > t0) {
				for(int i = 0; i < s.size() && t0 < s0; i++) {
					if(s[i] == '0' && t[i] == '1') {
						s[i] = '1';
						s1++, s0--, ans++;
					}
				}	
			}
			
			int cnt = 0;
			for(int i = 0; i < s.size(); i++) {
				if(s[i] != t[i]) cnt++;
			}
			
			ans += (cnt / 2);
		}
		
		cout << "Case " << tc << ": " << ans << '\n';
	}
	
	return 0;
}
