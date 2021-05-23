/* reference: codeplus/beakjoon */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

struct MaximumFlow {
	int N;
	vector<vector<int>> G;
	vector<bool> check;
	vector<int> pred;
	
	MaximumFlow(int N) : N(N) {
		G.resize(N);
		check.resize(N);
		pred.resize(N, -1);
	}
	
	void add_edge(int u, int v) {
		G[u].push_back(v);
	}
	
	bool dfs(int now) {
		if(now == -1) return true;
		for(auto& nxt : G[now]) {
			if(check[nxt]) continue;
			check[nxt] = 1;
			if(dfs(pred[nxt])) {
				pred[nxt] = now;
				return true;
			}
		}
		return false;
	}
	
	int flow() {
		int ans = 0;
		for(int i = 0; i < N; i++) {
			fill(check.begin(), check.end(), false);
			if(dfs(i)) ans++;
		}
		return ans;
	}
};

typedef pair<int,int> pii;

const int MAX = 55;

char board[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main() {
	int N, M; cin >> N >> M;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		cin >> board[i][j];
	}
	
	vector<pii> car, park;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		if(board[i][j] == 'C') car.emplace_back(i, j);
		else if(board[i][j] == 'P') park.emplace_back(i, j);
	}
	
	// car > park
	if(car.size() > park.size()) {
		cout << -1 << '\n';
		return 0;
	}
	
	// car not found
	if(car.size() == 0) {
		cout << 0 << '\n';
		return 0;
	}
	
	vector<vector<int>> parking_time(car.size(), vector<int>(park.size()));
	for(int i = 0; i < car.size(); i++) {
		vector<vector<int>> d(N, vector<int>(M, -1));
		queue<pii> q;
		auto start = car[i];
		d[start.fi][start.sc] = 0;
		q.push(start);
		
		while(!q.empty()) {
			int x = q.front().fi;
			int y = q.front().sc;
			q.pop();
			
			for(int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if(0 <= nx && nx < N && 0 <= ny && ny < M) {
					if(board[nx][ny] != 'X' && d[nx][ny] == -1) {
						d[nx][ny] = d[x][y] + 1;
						q.push({nx, ny});
					}
				}
			}
		}
		
		for(int j = 0; j < park.size(); j++) {
			parking_time[i][j] = d[park[j].fi][park[j].sc];
		}
	}
	
	int ans = -1;
	int L = 1, R = N * M;
	N = car.size(), M = park.size();
	while(L <= R) {
		int mid = (L + R) / 2;
		
		MaximumFlow mf(max(N, M));
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
			if(parking_time[i][j] != -1 && parking_time[i][j] <= mid) {
				mf.add_edge(i, j);
			}
		}
		
		// all car is parked
		if(mf.flow() == N) {
			if(ans == -1 || ans > mid) ans = mid;
			R = mid - 1;
		} else {
			L = mid + 1;
		}
	}
	cout << ans << '\n';
	
	return 0;
}
