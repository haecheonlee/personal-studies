#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 5e4 + 10;

int cnt[110];

int main() {
	int N; cin >> N;
	
	ll sum = 0;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		cnt[x]++;
		sum += x;
	}
	
	ll ans = sum;
	for(int i = 1; i <= 100; i++) {
		for(int j = 1; j <= 100; j++) {
			if(i == j) continue;
			if(cnt[i] && cnt[j]) {
			 	for(int k = 1; k * k <= i; k++) 
			 		if(i % k == 0) ans = min(ans, sum - i - j + i / k + j * k);
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
