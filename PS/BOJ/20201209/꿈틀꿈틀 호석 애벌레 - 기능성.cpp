#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 21;

int N, K;
int a[MAX], d[MAX][101];

int go(int n, int k) {
	if(n > N) return 0;
	
	int& ret = d[n][k];
	if(ret != -1) return ret;
	ret = 0;
	
	// skip
	ret = max(ret, go(n + 1, k));
	
	// take
	int x = 0;
	while(x < K && n <= N) x += a[n++];
	ret = max(ret, go(n, 0) + x - K);
	
	return ret;
}

int main() {
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	memset(d, -1, sizeof(d));
	cout << go(1, 0) << '\n';
	
	return 0;
}
