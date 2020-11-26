#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;
const int INF = 1e9;

int a[MAX];
int d[MAX][MAX];

int main() {
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++ ) cin >> a[i];

	memset(d, 0x3f, sizeof(d));
	queue<pii> q;
	q.push({1,0});
	d[1][0] = 0;
	
	while(!q.empty()) {
		int x = q.front().first;
		int m = q.front().second;
		q.pop();
		int nm = m + 1;
		
		int y = x + nm;
		// forward		
		if(N >= y) {
			if(d[y][nm] > d[x][m] + a[y]) {
				d[y][nm] = d[x][m] + a[y];
				q.push({y, nm});
			}
		}
		
		int z = x - m;
		// backward
		if(z >= 1) {
			if(d[z][m] > d[x][m] + a[z]) {
				d[z][m] = d[x][m] + a[z];
				q.push({z, m});
			}
		}
	}
	
	int ans = INF;
	for(int i = 0; i < MAX; i++) {
		if(d[N][i] >= INF) continue;
		ans = min(ans, d[N][i]);
	}
	cout << ans;

	return 0;
}
