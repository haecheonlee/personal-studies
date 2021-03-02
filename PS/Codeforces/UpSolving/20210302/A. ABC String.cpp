#include <iostream>
#include <stack>

using namespace std;

void solve() {
	string s; cin >> s;
	
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			for(int k = 0; k < 2; k++) {
				stack<int> stk;
				bool is_good = 1;
				for(auto& x : s) {
					int p = -1;
					
					if(x == 'A') p = i;
					if(x == 'B') p = j;
					if(x == 'C') p = k;
					
					if(p == 0) {
						stk.push(p);
					} else {
						if(stk.empty()) {
							is_good = 0;
							break;
						} else {
							stk.pop();
						}
					}
				}
				
				if(is_good && stk.empty()) {
					cout << "YES" << '\n';
					return;
				}
			}
		}
	}
	
	cout << "NO" << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
