#include <iostream>
#include <queue>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 2e5 + 10;
const int INF = 1e9;

int a[MAX_N];
int d[MAX_N][2];	// 0: friend, 1: me

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		d[i][0] = d[i][1] = INF;
	}
	
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	pq.push({0, {0, 0}});
	d[0][0] = 0;
	
	while(!pq.empty()) {
		int c = pq.top().fi;
		int x = pq.top().sc.fi;
		int p = pq.top().sc.sc;
		pq.pop();
		
		if(d[x][p] < c) continue;
		int skip = 0, np = p ^ 1, nx = x + 1;
		if(nx <= N) {
			if(a[nx] == 1 && p == 0) skip++;
			if(d[nx][np] > d[x][p] + skip) {
				d[nx][np] = d[x][p] + skip;
				pq.push({d[nx][np], {nx, np}});
			}
		}
		
		nx = x + 2;
		if(nx <= N) {
			if(a[nx] == 1 && p == 0) skip++;
			if(d[nx][np] > d[x][p] + skip) {
				d[nx][np] = d[x][p] + skip;
				pq.push({d[nx][np], {nx, np}});
			}
		}
	}

	cout << min(d[N][0], d[N][1]) << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
