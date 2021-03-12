#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX = 1e3 + 1;

int N, M;
int x[MAX], w[MAX];
ll d[MAX][MAX][2];
ll p[MAX];

ll go(int L, int R, int where) {
	if(L == 1 && R == N) return 0;
	
	ll& ret = d[L][R][where];
	if(ret != -1) return ret;
	ret = 1e18;
	
	int now = (where == 0 ? L : R);
	if(L - 1 >= 1) 
		ret = min(ret, go(L - 1, R, 0) + (x[now] - x[L - 1]) * (p[N] - p[R] + p[L - 1]));
	if(R + 1 <= N)
		ret = min(ret, go(L, R + 1, 1) + (x[R + 1] - x[now]) * (p[N] - p[R] + p[L - 1]));
		
	return ret;
}

int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> x[i] >> w[i];
	for(int i = 1; i <= N; i++) p[i] = p[i - 1] + w[i];

	memset(d, -1, sizeof(d));
	cout << go(M, M, 0) << '\n';

	return 0;
}
