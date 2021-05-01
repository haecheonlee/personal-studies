#include <iostream>
#include <queue>
#include <vector>

#define fi first
#define sc second

using namespace std;

typedef pair<int, int> pii;

const int MAX = 5e2 + 10;

int N, M;
char a[MAX][MAX];
int d[MAX][MAX];			// -1: not set, 0: failed, 1: success
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int getDir(char x) {
	if(x == 'L') return 0;
	else if(x == 'R') return 1;
	else if(x == 'U') return 2;
	else if(x == 'D') return 3;
	return -1;
}

void go(int sx, int sy) {
	vector<pii> visited; 
	visited.push_back({sx, sy});
	
	bool flag = 0;
	queue<pii> q;
	q.push({sx, sy});
	d[sx][sy] = 0;
	
	while(!q.empty()) {
		int x = q.front().fi;
		int y = q.front().sc;
		q.pop();
		
		int k = getDir(a[x][y]);
		int nx = x + dx[k];
		int ny = y + dy[k];
		
		if(0 <= nx && nx < N && 0 <= ny && ny < M) {
			visited.push_back({nx, ny});
			if(d[nx][ny] == -1) {
				d[nx][ny] = 0;
				q.push({nx, ny});
			} else if(d[nx][ny] == 1) {
				// already escaped
				flag = 1;
				break;
			}
		} else {
			// escape
			flag = 1;
			break;
		}
	}
	
	if(flag) for(auto& p : visited) d[p.fi][p.sc] = 1;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
		}
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) 
			if(d[i][j] == -1) 
				go(i, j);
	
	int ans = 0;
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < M; j++)
			if(d[i][j] == 1) 
				ans++;
	cout << ans << '\n';

	return 0;
}
