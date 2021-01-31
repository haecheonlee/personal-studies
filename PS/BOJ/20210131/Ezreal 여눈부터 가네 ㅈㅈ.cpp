#include <iostream>

using namespace std;

const int MAX_N = 1516;
const int MOD = 1e9 + 7;

long long d[MAX_N];

int main() {
	int N; cin >> N;
	d[1] = 0, d[2] = 1, d[3] = 1;

	for(int i = 4; i <= N; i++) {
		
		for(int k = 2; k <= i - 2; k++) {
			d[i] += d[k] * 2;
			d[i] %= MOD;
		}
		d[i]++;
	}
	cout << d[N];

	return 0;
}
