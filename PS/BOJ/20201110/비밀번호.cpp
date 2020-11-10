#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;
const int MOD = 1234567;

vector<int> a[10] { {7}, {2,4}, {1,3,5}, {2,6}, {1,5,7}, 
	     	    {2,4,6,8}, {3,5,9}, {4,8,0}, {5,7,9}, {6,8} };

int d[MAX][10];

int main() {
	int T;
	cin >> T;
	
	memset(d, 0, sizeof(d));
	for(int j = 0; j <= 9; j++) d[1][j] = 1;
	for(int i = 2; i < MAX; i++) {
		for(int j = 0; j <= 9; j++) {
			for(auto& x : a[j]) {
				d[i][x] += d[i - 1][j] % MOD;
				d[i][x] %= MOD;
			}
		}
	}

	while(T--) {
		int N;
		cin >> N;
		
		int ans = 0;
		for(int j = 0; j <= 9; j++) {
			ans += d[N][j];
			ans %= MOD;
		}
		cout << ans << '\n';
	}

	return 0;
}
