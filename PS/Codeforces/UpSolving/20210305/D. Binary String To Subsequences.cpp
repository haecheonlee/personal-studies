/* editorial */

#include <iostream>
#include <stack>

#define sz(x) (int)x.size()

using namespace std;

const int MAX_N = 2e5 + 1;

int ans[MAX_N];

void solve() {
	int N; cin >> N;
	string s; cin >> s;
	
	stack<int> p0, p1;
	for(int i = 0; i < N; i++) {
		int p = sz(p0) + sz(p1);
		
		if(s[i] == '0') {
			if(p1.empty()) {
				p0.push(p);
			} else {
				p = p1.top();
				p1.pop();
				p0.push(p);
			}
		} else {
			if(p0.empty()) {
				p1.push(p);
			} else {
				p = p0.top();
				p0.pop();
				p1.push(p);
			}
		}
		
		ans[i] = p;
	}
	
	cout << sz(p0) + sz(p1) << '\n';
	for(int i = 0; i < N; i++) cout << ans[i] + 1 << ' ';
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
