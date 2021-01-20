/* reference: https://blog.naver.com/jinhan814/222194845239 */

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 150;
const int INF = 1e9;

enum { R, U, L, D};
struct Edge {
	int x, y, cost_r, cost_l; //destination, cost
};

struct P {
	int r, l, x, y; //cost_r, cur
	
	bool operator < (const P& p) const {
		return r < p.r;
	}
	
	bool operator > (const P& p) const {
		return p < *this;
	}
};

int N, M, K;
int board[MAX][MAX];
vector<Edge> G[MAX][MAX];
int d[1501][MAX][MAX];

int conv(char c) {
	switch(c) {
		case 'R': return R;
		case 'U': return U;
		case 'L': return L;
		case 'D': return D;
	}
	
	return -1;
}

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

int main() {
	memset(d, 0x3f, sizeof(d));
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; i++) {
		string s; cin >> s;
		for(int j = 0; j < M; j++) {
			board[i][j] = conv(s[j]);
		}
	}

	// graph construction
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			int dir = board[i][j];
			
			// cw
			for(int k = 0; k < 4; k++) {
				int nx = i + "1012"[(dir - k + 4) % 4] - '1';
				int ny = j + "2101"[(dir - k + 4) % 4] - '1';
				if(OOB(nx, ny)) continue;
				G[i][j].push_back({nx, ny, k, 0});
			}
			
			// ccw
			for(int k = 0; k < 4; k++) {
				int nx = i + "1012"[(dir + k) % 4] - '1';
				int ny = j + "2101"[(dir + k) % 4] - '1';
				if(OOB(nx, ny)) continue;
				G[i][j].push_back({nx, ny, 0, k});
			}
		}
	}
	
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({0, 0, 0, 0});
	d[0][0][0] = 0;
	
	while (!pq.empty()) {
		int r = pq.top().r;
		int l = pq.top().l;
		int x = pq.top().x;
		int y = pq.top().y;
		pq.pop();
		
		if (d[l][x][y] != r) continue;
		if (x == N - 1 && y == M - 1) {
			cout << "Yes" << '\n';
			return 0;
		}
		for (auto& g : G[x][y]) {
			int nx = g.x;
			int ny = g.y;
			int cost_r = g.cost_r;
			int cost_l = g.cost_l;
			
			if (r + cost_r > K || l + cost_l > K) continue;
			if (d[l + cost_l][nx][ny] > r + cost_r) {
				d[l + cost_l][nx][ny] = r + cost_r;
				pq.push({ r + cost_r, l + cost_l, nx, ny });
			}
		}
	}
	cout << "No" << '\n';

	return 0;
}
