#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int N;
		cin >> N;
		
		int r_mx = 0, r_sum = 0;
		for(int i = 0; i < N; i++) {
			int x;
			cin >> x;
			
			r_sum += x;
			r_mx = max(r_mx, r_sum);
		}
		
		int M;
		cin >> M;
		
		int b_mx = 0, b_sum = 0;
		for(int i = 0; i < M; i++) {
			int x;
			cin >> x;
			
			b_sum += x;
			b_mx = max(b_mx, b_sum);
		}
		
		cout << max(0, r_mx + b_mx) << '\n';
	}

	return 0;
}
