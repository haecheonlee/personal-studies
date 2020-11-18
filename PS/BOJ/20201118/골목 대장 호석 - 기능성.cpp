#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define eb emplace_back

using namespace std;

typedef pair<int,int> pii;

const int MAX = 11;
const int INF = 1e9;

vector<pii> G[MAX];
int d[MAX][1001];

int main() {
	int N, M, A, B, C;
	cin >> N >> M >> A >> B >> C;

	for(int i = 0; i < M; i++) {
		int U, V, COST;
		cin >> U >> V >> COST;
		
		G[U].eb(make_pair(V, COST));
		G[V].eb(make_pair(U, COST));
	}
	
	memset(d, 0x3f, sizeof(d));
	priority_queue<pair<pii,int>> q;
	q.push({{0, 0}, A});
	d[A][0] = 0;
	
	while(!q.empty()) {
		int x = q.top().second;
		int c = -q.top().first.first;
		int mx = q.top().first.second;
		q.pop();
		
		if(d[x][mx] < c) continue;
		for(auto& next : G[x]) {
			int y = next.first;
			int nc = c + next.second;
			int nmx = max(next.second, mx);
		
			if(nc > C) continue;	
			if(d[y][nmx] > nc) {
				d[y][nmx] = nc;
				q.push({{-nc, nmx}, y});
			}
		}
	}
	
	int ans = INF;
	for(int i = 1; i <= 1000; i++) {
		if(d[B][i] >= INF) continue;
		ans = min(ans, i);
	}
	cout << (ans == INF ? -1 : ans) << '\n';

	return 0;
}
