#include <iostream>
#include <queue>
#include <stack>
#include <map>

using namespace std;

const int MAX_N = 2e2 + 10;

int a[MAX_N];
map<int, bool> m;

int main() {
	int N, K; cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> a[i];

	
	queue<int> q;
	for(int i = 1; i <= N; i++) {
		int L = (int)q.size();
		if(L == K) {
			if(!m[a[i]]) {
				m[q.front()] = 0; q.pop();
				q.push(a[i]), m[a[i]] = 1;
			}
		} else {
			if(!m[a[i]]) q.push(a[i]), m[a[i]] = 1;
		}
	}

	stack<int> ans;
	while(!q.empty()) {
		ans.push(q.front());
		q.pop();
	}
	
	cout << (int)ans.size() << '\n';
	while(!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}
