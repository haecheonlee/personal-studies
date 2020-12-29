#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 11;

int N, group_num = 1;
char board[MAX][MAX];
int g[MAX][MAX];
bool check[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int sx, int sy) {
	queue<pii> q;
	q.push({sx, sy});
	g[sx][sy] = group_num;

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(0 <= nx && nx < N && 0 <= ny && ny < N) {
				if(board[nx][ny] == '.' && g[nx][ny] == 0) {
					g[nx][ny] = group_num;
					q.push({nx, ny});
				}
			}
		}
	}
}

void bfs2(int sx, int sy) {
	queue<pii> q;
	check[sx][sy] = true;
	q.push({sx, sy});
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(0 <= nx && nx < N && 0 <= ny && ny < N) {
				if(board[nx][ny] == '.' && !check[nx][ny]) {
					check[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
	}
}

bool chk(int sx, int sy) {
	memset(check, false, sizeof(check));
	
	int cnt = 0;
	board[sx][sy] = '@';
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(board[i][j] == '.' && !check[i][j] && g[sx][sy] == g[i][j]) {
				bfs2(i, j);
				cnt++;
			}
		}
	}
	board[sx][sy] = '.';
	
	return cnt >= 2;
}

int main() {
	cin >> N;
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) 
			cin >> board[i][j];
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(board[i][j] == '.' && g[i][j] == 0) {
				bfs(i, j);
				group_num++;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < N; j++)
			if(board[i][j] == '.' && chk(i, j)) ans++;
	cout << ans << '\n';

	return 0;
}
