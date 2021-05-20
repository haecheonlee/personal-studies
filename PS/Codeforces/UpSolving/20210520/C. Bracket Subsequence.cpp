#include <iostream>
#include <stack>

using namespace std;

const int MAX_N = 2e5 + 10;

int p[MAX_N];
bool check[MAX_N];

int main() {
	int N, K; cin >> N >> K;
	string s; cin >> s;

	stack<int> stk;
	for(int i = 0; i < N; i++) {
		if(s[i] == '(') {
			stk.push(i);
		} else {
			if(!stk.empty()) {
				int j = stk.top(); stk.pop();
				p[j] = i, p[i] = j;
			}
		}
	}
	
	for(int i = 0; i < N && K; i++) {
		if(!check[i]) {
			check[i] = check[p[i]] = true;
			K -= 2;
		}
	}
	
	for(int i = 0; i < N; i++) if(check[i]) cout << s[i];

	return 0;
}
