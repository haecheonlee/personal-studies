#include <iostream>
#include <stack>

#define sz(x) (int)x.size()

using namespace std;

int main() {
	string s; cin >> s;
	
	stack<char> stk;
	bool win = false;
	for(int i = 0; i < sz(s); i++) {
		if(stk.empty()) {
			stk.push(s[i]);
		} else {
			if(stk.top() == s[i]) stk.pop(), win = !win;
			else stk.push(s[i]);
		}
	}
	cout << (win ? "Yes" : "No") << '\n';
	
	return 0;
}
