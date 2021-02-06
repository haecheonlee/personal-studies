#include <iostream>
#include <queue>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 5e5 + 1;

int a[MAX_N];
queue<int> q[6];

bool go(int now, int L) {
	if(now == 6) return 1;

	bool ret = 0;
	while(!q[now].empty()) {
		int x = q[now].front();
		q[now].pop();
		if(L < x) if(go(now + 1, x)) return 1;
	}
	
	return 0;
}

int main() {
	fastio

	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		if(a[i] == 4) q[0].push(i);
		else if(a[i] == 8) q[1].push(i);
		else if(a[i] == 15) q[2].push(i);
		else if(a[i] == 16) q[3].push(i);
		else if(a[i] == 23) q[4].push(i);
		else if(a[i] == 42) q[5].push(i);
	}
	
	int ans = 0;
	while(!q[0].empty()) {
		ans += go(1, q[0].front());	
		q[0].pop();
	}
	cout << N - (ans * 6) << '\n';

	return 0;
}
