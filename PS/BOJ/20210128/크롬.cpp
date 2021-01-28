#include <iostream>

using namespace std;

struct Tab {
	int c, m, p;	
};

const int MAX_N = 1e2 + 1;

Tab a[MAX_N];
int d[1001][2001];

int main() {
	int N, C, M; cin >> N >> C >> M;
	for(int i = 0; i < N; i++) cin >> a[i].c >> a[i].m >> a[i].p;

	for(int i = 0; i < N; i++) {
		for(int p = 1000; p >= 0; p--) {
			int pd = p - a[i].p;
			if(pd < 0) break;
			
			for(int c = 2000; c >= 0; c--) {
				int cd = c - a[i].c;
				if(cd < 0) break;
				
				if((pd == 0 && cd == 0) || d[pd][cd])
 					d[p][c] = max(d[p][c], d[p - a[i].p][c - a[i].c] + a[i].m);
			}
		}
	}
	
	int ans = -1;
	for(int p = 1000; p >= 0; p--) {
		for(int c = 2000; c >= C; c--) {
			if(d[p][c] && d[p][c] >= M) {
				if(ans == -1 || ans > p) ans = p;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
