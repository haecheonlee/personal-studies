#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 1;

int N;
int a[2][MAX_N];
ll d[2][MAX_N];

ll go(int p, int n) {
	if(n > N) return 0;
	
	ll& ret = d[p][n];
	if(ret != -1) return ret;
	ret = 0;
	
	return ret = max(go(1 - p, n + 1) + a[p][n], go(p, n + 1));
}

int main() {
	cin >> N;
	for(int i = 0; i < 2; i++)
		for(int j = 1; j <= N; j++)  
			cin >> a[i][j];

	memset(d, -1, sizeof(d));
	ll ans = max(go(0, 1), go(1, 1));
	cout << ans << '\n';
	
	return 0;
}
