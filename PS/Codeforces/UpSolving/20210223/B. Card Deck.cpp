#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 1e5 + 1;

int a[MAX_N], p[MAX_N];

void solve() {
	int N; cin >> N;
	int p[N + 1] {0};
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		p[i] = max(p[i - 1], a[i]);	
	}
	
	stack<int> stk;
	vector<int> ans;
	for(int i = N; i >= 1; i--) {
		stk.push(a[i]);
		if(p[i] == a[i]) {
			while(!stk.empty()) {
				ans.push_back(stk.top());
				stk.pop();
			}
		}
	}
	
	for(int i = 0; i < N; i++) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
