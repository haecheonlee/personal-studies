#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 1e5 + 2e4 + 10;

bool chk[MAX_N];

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	
	for(int i = 0; i < N; i++) {
		for(int k = log2(a[i]); k <= 31; k++) {
			unsigned int b = (unsigned int)1 << k;
			int x = lower_bound(a.begin() + i + 1, a.end(), b - a[i]) - a.begin();
			if(x < N && a[x] + a[i] == b) {
				chk[i] = chk[x] = 1;
			}
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		if(a[i - 1] == a[i] && chk[i - 1]) chk[i] = 1;
		cnt += chk[i];
	}
	cout << N - cnt << '\n';
	
	return 0;
}
