#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N;
		cin >> N;

		int ans = -1;
		int p[N + 1];
		memset(p, -1, sizeof(p));

		for (int i = 0; i < N; i++) {
			int x;
			cin >> x;

			if(p[x] == -1) {
				p[x] = i;
			}
			else {
				int d = i - p[x] + 1;
				p[x] = i; 
				if(ans == -1 || ans > d) ans = d;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
