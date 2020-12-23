#include <iostream>

using namespace std;

int main() {
	int N;
	while(cin >> N) {
		int a[N];
		for(int i = 0; i < N; i++) cin >> a[i];

		if(N == 1) {
			cout << "Jolly\n";
		} else {

			bool check[N] { false };
			for(int i = 1; i < N; i++) {
				int diff = abs(a[i] - a[i - 1]);
				check[diff] = 1;
			}
			
			bool ans = true;
			for(int i = 1; i < N; i++) if(!check[i]) { ans = false; break; }
			
			cout << (ans ? "Jolly" : "Not jolly") << '\n';
		}
	}

	return 0;
}
