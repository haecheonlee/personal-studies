#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	int a[K];
	for(int i = 0; i < K; i++) cin >> a[i];

	char ans[N][M];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) ans[i][j] = '0';
	}
	
	for(int k = 0; k < K; k++) {
		for(int j = 0; j < M; j++) {
			for(int i = 0; i < N; i++) {
				if(ans[i][j] == '0') {
					ans[i][j] = '1' + k;
					a[k]--;
				}
				if(!a[k]) break;
			}
			if(!a[k]) break;
		}	
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cout << ans[i][j];
		cout << '\n';
	}

	return 0;
}
