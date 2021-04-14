#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

int cnt[MAX_N];
long long d[MAX_N][2];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		cnt[x]++;
	}
	
	long long ans = 0;
	for(int i = 1; i < MAX_N; i++) {
		if(i - 2 >= 1) d[i][0] = max(d[i - 2][1], d[i - 1][1]);
		d[i][1] = max(d[i - 1][0] + cnt[i] * 1LL * i, d[i - 2][1] + cnt[i] * 1LL * i);
		ans = max(d[i][0], d[i][1]);
	}
	cout << ans << '\n';
	
	return 0;
}
