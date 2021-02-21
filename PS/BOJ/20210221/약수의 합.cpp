#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX = 1e6 + 1;

long long d[MAX], p[MAX];

void solve() {
	int N; cin >> N;
	cout << p[N] << '\n';
}

int main() {
	fastio
	
	for(int i = 1; i * i < MAX; i++) {
		for(int j = i; j < MAX; j += i) {
			if(i * i <= j) {
				int k = j / i;
				d[j] += k;
				if(k != i) d[j] += i;
			}
		}
	}
	for(int i = 1; i < MAX; i++) p[i] = p[i - 1] + d[i];
	
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
