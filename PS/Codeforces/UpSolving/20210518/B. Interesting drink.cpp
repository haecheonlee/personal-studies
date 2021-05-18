#include <iostream>

using namespace std;

const int MAX = 1e5 + 10;

int cnt[MAX];

int main() {
	int N; cin >> N;
	
	for(int i = 0; i < N; i++) {
		int x; cin >> x;
		cnt[x]++;
	}
	for(int i = 1; i < MAX; i++) cnt[i] += cnt[i - 1];
	
	int Q; cin >> Q;
	while(Q--) {
		int x; cin >> x;
		x = min(x, 100000);
		cout << cnt[x] << '\n';
	}

	return 0;
}
