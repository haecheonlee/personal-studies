#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;

int N, M;
int a[MAX][MAX];
bool check[MAX][MAX];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool bfs(int L) {
	memset(check, false, sizeof(check));
	queue<pii> q;
	q.push({0,0});
	check[0][0] = true;

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(0 <= nx && nx < N && 0 <= ny && ny < M) {
				int d = a[nx][ny] - a[x][y];
				if(d <= L && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push({nx,ny});
				}
			}
		}		
	}
	
	return check[N - 1][M - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cin >> a[i][j];
	}
	
	int ans = 1e9 + 1;
	int L = 0, R = 1e9;
	while (L <= R) {
		int mid = (L + R) / 2;
		if(bfs(mid)) {
			ans = min(ans, mid);
			R = mid - 1;
		} else {
			L = mid + 1;
		}
	}
	cout << ans;

	return 0;
}
