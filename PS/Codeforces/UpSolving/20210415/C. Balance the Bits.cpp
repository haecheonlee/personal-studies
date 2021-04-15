/* editorial */

#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	string s; cin >> s;
	
	int cnt = 0;
	for(int i = 0; i < N; i++) cnt += (s[i] == '1');
	
	if(cnt % 2 == 1 || s[0] == '0' || s.back() == '0') {
		cout << "NO" << '\n';
	} else {
		string a, b;
		int k = 0;
		bool flip = false;
		
		for(int i = 0; i < N; i++) {
			if(s[i] == '1') {
				a.push_back(2 * k < cnt ? '(' : ')');
				b.push_back(a.back());
				k++;
			} else {
				a.push_back(flip ? '(' : ')');
				b.push_back(flip ? ')' : '(');
				flip = !flip;
			}
		}
		cout << "YES" << '\n';
		cout << a << '\n' << b << '\n';
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
