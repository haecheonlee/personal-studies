#include <iostream>

using namespace std;

int main() {
	int N, M; cin >> N >> M;
	
	if(M % N != 0) cout << -1 << '\n';
	else {
		int p = M / N;
		int ans = 0;
		while(1 < p) {
			if(p % 6 == 0) {
				ans += 2, p /= 6;
				continue;
			}
			
			if(p % 2 == 0) {
				ans++, p /= 2;
				continue;
			}
			
			if(p % 3 == 0) {
				ans++, p /= 3;
				continue;	
			}

			cout << -1 << '\n';
			return 0;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
