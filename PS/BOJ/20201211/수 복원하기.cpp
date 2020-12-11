#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int N;
		cin >> N;
		
		int p[N + 1] {0};
		
		int x = N;
		for(int i = 2; i * i <= x; i++) {
			if(x % i == 0) {
				x /= i;
				p[i]++;
				i = 1;
			}
		}
		
		if(x == N) {
			cout << N << ' ' << 1 << '\n';
		} else {
			p[x]++;
			for(int i = 2; i <= N; i++) {
				if(p[i]) cout << i << ' ' << p[i] << '\n';
			}
		}
	}

	return 0;
}
