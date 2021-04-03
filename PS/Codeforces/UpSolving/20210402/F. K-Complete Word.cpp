#include <iostream>

using namespace std;

const int MAX_N = 2e5 + 10;

int p[MAX_N];
int cnt[MAX_N][26];

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	if(x != y) p[y] = x;
}

void print(int N) {
	for(int i = 0; i < N; i++) cout << p[i] << ' ';
	cout << '\n';
}

void solve() {
	int N, K; cin >> N >> K;
	string s; cin >> s;
	for(int i = 0; i < N; i++) {
		p[i] = i;
		for(int j = 0; j < 26; j++) cnt[i][j] = 0;
	}
	
	for(int i = 0; i < N / 2; i++) Union(p[i], p[N - i - 1]);
	for(int i = K; i < N; i++) Union(p[i - K], p[i]);
	for(int i = 0; i < N; i++) cnt[Find(i)][s[i] - 'a']++;
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		int found = 0, mx = 0;
		for(int j = 0; j < 26; j++) {
			if(cnt[i][j]) found += cnt[i][j], mx = max(mx, cnt[i][j]);
		}
		ans += (found - mx);
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
