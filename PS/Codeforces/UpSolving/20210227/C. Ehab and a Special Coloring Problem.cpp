#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 1;

int ans[MAX_N];

int main() {
	int K = 1;
	for(int i = 2; i < MAX_N; i++) {
		if(!ans[i]) {
			ans[i] = K;
			for(int j = i + i; j < MAX_N; j += i) ans[j] = K;
			K++;
		}
	}
	
	int N; cin >> N;
	for(int i = 2; i <= N; i++) cout << ans[i] << ' ';
	
	return 0;
}
