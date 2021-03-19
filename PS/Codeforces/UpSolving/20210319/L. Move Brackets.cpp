#include <iostream>
#include <stack>

using namespace std;

void solve() {
	int N; cin >> N;
	string s; cin >> s;

	stack<char> stk;
	for(int i = 0; i < N; i++) {
		if(s[i] == '(') stk.push('(');
		else if(s[i] == ')') {
			if(!stk.empty()) stk.pop();
		}
	}

	cout << N - (N - (int)stk.size()) << '\n'; 
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
