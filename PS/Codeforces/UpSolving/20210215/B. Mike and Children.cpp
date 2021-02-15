#include <iostream>

using namespace std;

const int MAX = 2e5 + 10;

int cnt[MAX];

int main() {
	int N; cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) cnt[a[i] + a[j]]++;
	}
	
	int ans = 0;
	for(int i = 0; i < MAX; i++) ans = max(ans, cnt[i]);
	cout << ans << '\n';
	
	return 0;
}
