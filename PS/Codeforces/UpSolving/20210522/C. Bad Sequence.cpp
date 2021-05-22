#include <iostream>
#include <stack>

using namespace std;

const int MAX_N = 2e5 + 10;

bool check[MAX_N];

int main() {
	int N; cin >> N;
	string s; cin >> s;
	
	stack<int> stk; 
	for(int i = 0; i < N; i++) {
		if(s[i] == '(') {
			stk.push(i);
		} else {
			if(!stk.empty()) {
				int L = stk.top(); stk.pop();
				check[L] = check[i] = true;
			}
		}
	}
	
	int L = 0, R = 0;
	for(int i = 0; i < N; i++) {
		if(!check[i]) {
			if(s[i] == '(') L++;
			else R++;
		}
	}
	
	if((L == 0 && R == 0) || (L == 1 && R == 1)) cout << "Yes" << '\n';
	else cout << "No" << '\n';

	return 0;
}
