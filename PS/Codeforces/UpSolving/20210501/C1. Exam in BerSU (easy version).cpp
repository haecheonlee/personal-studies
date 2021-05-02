#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 1e2 + 10;

int a[MAX_N];

int main() {
	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	multiset<int> taken;
	int pSum = 0;
	for(int i = 1; i <= N; i++) {
		int cnt = 0;
		int sum = pSum;
		for(auto it = taken.rbegin(); it != taken.rend() && sum + a[i] > M; it++) {
			sum -= *it;
			cnt++;
		}
		pSum += a[i];
		taken.insert(a[i]);
		cout << cnt << ' ';
	}

	return 0;
}
