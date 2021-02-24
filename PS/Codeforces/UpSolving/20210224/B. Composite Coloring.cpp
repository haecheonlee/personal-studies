#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e3 + 1;

vector<int> primes;
bool check[MAX];

void solve() {
	int N; cin >> N;
	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	int color = 1;
	int ans[N + 1] { 0 };
	for(int k = 0; k < primes.size(); k++) {
		bool used = 0;
		for(int i = 1; i <= N; i++) {
			if(ans[i]) continue;
			if(a[i] % primes[k] == 0) {
				ans[i] = color;
				used = 1;
			}
		}
		color += used;
	}
	
	cout << color - 1 << '\n';
	for(int i = 1; i <= N; i++) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	for(int i = 2; i * i < MAX; i++) {
		if(!check[i]) {
			primes.push_back(i);
			for(int k = i; k * k < MAX; k += i) check[k] = 1;
		}
	}

	int T; cin >> T;
	while(T--) solve();

	return 0;
}
