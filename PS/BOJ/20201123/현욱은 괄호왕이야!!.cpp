#include <iostream>
#include <stack>

using namespace std;

const int MAX = 2e5 + 1;

bool check[MAX];

int main() {
	int N;
	cin >> N;
	
	string s;
	cin >> s;
	
	stack<int> stk;
	for(int i = 0; i < N; i++) {
		if(s[i] == '(') {
			stk.push(i);
		} else {
			if(!stk.empty()) {
				check[stk.top()] = check[i] = 1;
				stk.pop();
			}
		}
	}
	
	int ans = 0, L = -1;
	for(int i = 0; i < N; i++) {
		if(check[i]) {
			if(L == -1) L = i;
		} else {
			if(L != -1) {
				ans = max(ans, i - L);
				L = -1;
			}
		}
	}
	
	if(L != -1) ans = max(ans, N - L);
	cout << ans << '\n';
	
	return 0;
}
