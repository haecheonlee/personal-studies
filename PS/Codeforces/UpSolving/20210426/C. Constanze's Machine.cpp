/* reference: editorial */

#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
	string s; cin >> s;
	int N = s.size();
	
	for(auto& x : s) {
		if(x == 'w' || x == 'm') {
			cout << 0 << '\n';
			return 0;
		}
	}
	
	int d[N + 1] { 0 };
	d[0] = d[1] = 1;
	for(int i = 2; i <= N; i++) {
		d[i] = d[i - 1];
		if(s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n'))
			d[i] = (d[i] + d[i - 2]) % MOD;
	}
	cout << d[N] << '\n';

	return 0;
}
