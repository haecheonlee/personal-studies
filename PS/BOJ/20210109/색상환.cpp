/* reference: https://akim9905.tistory.com/71 */

#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 3;
const int MAX = 1e3 + 1;

int N, K;
int d[MAX][MAX];

int main() {
	cin >> N >> K;
	
	for(int i = 0; i <= N; i++) 
		d[i][1] = i, d[i][0] = 1;

	for(int i = 2; i <= N; i++) {
		for(int j = 2; j <= K; j++) {
			d[i][j] = (d[i - 2][j - 1] + d[i - 1][j]) % MOD;
		}
	}

	int ans = (d[N - 1][K] + d[N - 3][K - 1]) % MOD;
	cout << ans << '\n';

	return 0;
}
