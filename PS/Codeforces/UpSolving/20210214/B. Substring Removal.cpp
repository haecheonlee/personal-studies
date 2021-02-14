/* editorial */

#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;
	string s; cin >> s;
	
	int cntl = 0;
	for(int i = 0; i < N; i++) {
		if(s[0] == s[i]) cntl++;
		else break;
	}
	
	int cntr = 0;
	for(int i = N - 1; i >= 0; i--) {
		if(s[N - 1] == s[i]) cntr++;
		else break;
	}
	
	if(s[0] == s[N - 1]) cout << ((cntl + 1) * 1LL * (cntr + 1)) % 998244353 << '\n';
	else cout << (cntl + cntr + 1) % 998244353 << '\n';

	return 0;
}
