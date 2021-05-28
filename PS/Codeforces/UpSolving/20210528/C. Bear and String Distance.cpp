#include <iostream>

using namespace std;

int main() {
	int N, K; cin >> N >> K;
	string s; cin >> s;
	
	if(K == 0) {
		cout << s << '\n';
		return 0;
	}
	
	string ans = s;
	for(int i = 0; i < N && K; i++) {
		char x = 'a', c = abs(s[i] - 'a');
		for(int j = 0; j < 26; j++) {
			int nc = abs(('a' + j) - s[i]);
			if(nc > c) x = 'a' + j, c = nc;
			
			if(nc == K) {
				ans[i] = 'a' + j;
				cout << ans << '\n';
				return 0;
			}
		}
		
		ans[i] = x;
		K -= c;
	}
	
	cout << -1 << '\n';
	
	return 0;
}
