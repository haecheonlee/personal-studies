#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	while(T--) {
		int N, M;
		cin >> N >> M;

		bool check[101] { false };
		for(int i = 0; i < N; i++) {
			int x;
			cin >> x;

			check[x] = 1;
		}

		int ans = 0;
		for(int i = 0; i < M; i++) {
			int x;
			cin >> x;

			if(check[x]) ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}
