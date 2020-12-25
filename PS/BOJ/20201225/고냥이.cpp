#include <iostream>

#define sz(x) (int)(x.size())

using namespace std;

int p[26];

int main() {
	int N;
	cin >> N;
	
	string s;
	cin >> s;
	
	int ans = 0;
	int cnt = 0, state = 0;
	int L = 0, R = 0;
	while(R < sz(s)) {
		if(cnt <= N) {
			int pos = s[R] - 'a';
			
			if(p[pos] == 0) cnt++, state |= (1 << pos);
			p[pos]++;
			
			R++;
		} else {
			int pos = s[L] - 'a';
			
			p[pos]--;
			if(p[pos] == 0) cnt--, state ^= (1 << pos);
			
			L++;
		}
		
		if(cnt <= N) ans = max(ans, R - L);
	}
	
	cout << ans << '\n';

	return 0;
}
