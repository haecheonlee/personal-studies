#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1e3 + 1;

int N;
int a[MAX];
int d[MAX][MAX];

int go(int now, int mx) {
	if(now == N + 1) return 0;
	
	int& ret = d[now][mx];
	if(ret != -1) return ret;
	ret = 0;
	
	if(a[mx] < a[now]) ret = max(ret, go(now + 1, now) + a[now]);
	ret = max(ret, go(now + 1, mx));
	
	return ret;
}

int main() {
	cin >> N;
	
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	memset(d, -1, sizeof(d));
	int ans = go(0, 0);
	cout << ans << '\n';
	
	return 0;
}
