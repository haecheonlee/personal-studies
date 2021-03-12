/* reference: Nakagawa.Kanon */

#include <iostream>
#include <cmath>

using namespace std;

int ans = 1, res = 1;

int main() {
	int N; cin >> N;
	int M = N;
	for(int i = 2; i <= N; i++) {
		if(M % i) continue;
		int cnt = 0;
		while(M % i == 0) {
			M /= i;
			cnt++;
		}
		ans *= i;
		res = max(res, cnt);
	}
	
	M = N;
	bool same = 1;
	for(int i = 2; i <= N; i++) {
		if(M % i) continue;
		int cnt = 0;
		while(M % i == 0) {
			M /= i;
			cnt++;
		}
		if(res > cnt) same = 0;
	}
	
	int bit = log2(res) + 1;
	cout << ans << " ";
	if(res & (res - 1)) cout << bit + 1;
	else if(same) cout << bit - 1;
	else cout << bit;
	
	return 0;
}
