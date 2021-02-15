#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iomanip>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 50;

int N, M, K;
char board[MAX][MAX];
bool check[MAX][MAX];
int g[MAX][MAX], d[MAX][MAX], gx[20];
int dd[(1 << 15)][20];
vector<pii> G[20];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool chk(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

void connectIsland(int sx, int sy) {
	memset(check, false, sizeof(check));
	
	queue<pii> q;
	q.push({sx, sy});
	check[sx][sy] = 1;
	
	while(!q.empty()) {
		int x = q.front().fi;
		int y = q.front().sc;
		q.pop();
		g[x][y] = K;
		
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(chk(nx, ny) && board[nx][ny] == 'X' && !check[nx][ny]) {
				check[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
	
	K++;
}

void makeEdges(int g_num) {
	memset(d, 0x3f, sizeof(d));
	memset(gx, 0x3f, sizeof(gx));

	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(g[i][j] == g_num) {
				d[i][j] = 0;
				pq.push({0, {i, j}});
			}
		}
	}
	gx[g_num] = 0;

	while(!pq.empty()) {
		int c = pq.top().fi;
		int x = pq.top().sc.fi;
		int y = pq.top().sc.sc;
		pq.pop();

		if(d[x][y] < c) continue;
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(chk(nx, ny) && board[nx][ny] != '.') {
				int group = g[nx][ny];

				if(board[nx][ny] == 'X') {
					if(d[nx][ny] > c) {
						d[nx][ny] = c;
						gx[group] = min(gx[group], c);
						pq.push({c, {nx, ny}});
					}
				} else if(board[nx][ny] == 'S') {
					int nc = c + 1;
					if(d[nx][ny] > nc) {
						d[nx][ny] = nc;
						gx[group] = min(gx[group], nc);
						pq.push({nc, {nx, ny}});
					}	
				}
			}
		}
	}

	for(int i = 0; i < K; i++) {
		if(i != g_num) G[g_num].push_back({i, gx[i]});
	}
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) 
			cin >> board[i][j];
			
	memset(g, -1, sizeof(g));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(board[i][j] == 'X' && g[i][j] == -1) 
				connectIsland(i, j);
	
	for(int k = 0; k < K; k++) makeEdges(k);
	
	// dijkstra starts
	memset(dd, 0x3f, sizeof(dd));
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	for(int i = 0; i < K; i++) {
		pq.push({0, {1 << i, i}});
		dd[1 << i][i] = 0;
	}
		
	while(!pq.empty()) {
		int c = pq.top().fi;
		int s = pq.top().sc.fi;
		int x = pq.top().sc.sc;
		pq.pop();

		if(s == (1 << K) - 1) {
			cout << c << '\n';
			break;
		}

		if(dd[s][x] < c) continue;
		for(auto& nxt : G[x]) {
			int y = nxt.fi;
			int ns = s | (1 << y);
			int nc = nxt.sc + c;
			
			if(dd[ns][y] > nc) {
				dd[ns][y] = nc;
				pq.push({nc, {ns, y}});
			}
		}
	}

	return 0;
}
