#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define sz(x) (int)x.size()
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 15;

int a[MAX_N];
int d[2][1 << (MAX_N + 1)];
int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	memset(d, 0x3f, sizeof(d));
	priority_queue<pair<pii,pii>, vector<pair<pii,pii>>, greater<pair<pii,pii>>> pq;
	d[0][(1 << N) - 1] = 0;
	pq.push({{0, 0}, {(1 << N) - 1, 0}});
	
	while(!pq.empty()) {
		int t = pq.top().fi.fi;
		int p = pq.top().fi.sc;
		int s = pq.top().sc.fi;
		int ss = pq.top().sc.sc;
		pq.pop();
	
		if(d[p][s] < t) continue;
		if(p == 0) {
			// LEFT TO RIGHT
			for(int i = 0; i < N; i++) {
				for(int j = i + 1; j < N; j++) {
					if(s & (1 << i) && (s & (1 << j))) {
						int rs = (1 << i) | (1 << j);
						int nt = t + max(a[i], a[j]);

						if(d[1][s ^ rs] > nt) {
							d[1][s ^ rs] = nt;
							pq.push({{nt, 1}, {s ^ rs, ss | rs}});
						}
					}
				}
			}
		} else {
			// RIGHT TO LEFT
			for(int i = 0; i < N; i++) {
				if(ss & (1 << i)) {
					int rs = (1 << i);
					int nt = t + a[i];
					
					if(d[0][s | rs] > nt) {
						d[0][s | rs] = nt;
						pq.push({{nt, 0}, {s | rs, ss ^ rs}});
					}
				}
			}
		}
	}
	cout << d[1][0] << '\n';
	
	return 0;	
}
