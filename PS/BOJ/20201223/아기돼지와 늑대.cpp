#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e2;

int N, M;
char board[MAX][MAX];
bool check[MAX][MAX];
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

bool chk(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;	
}

int main() {
	cin >> N >> M;

	queue<pii> q;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> board[i][j];
			
			if(board[i][j] == 'W') {
				check[i][j] = true;
				q.push({i,j});
			}
		}
	}
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(chk(nx,ny)) {
				if(board[nx][ny] == '#') continue;
				
				if(board[nx][ny] == '.') {
					if(!check[nx][ny]) {
						check[nx][ny] = true;
						q.push({nx,ny});
					}
				} else if(board[nx][ny] == '+') {
					while(board[nx][ny] == '+' && chk(nx, ny)) nx += dx[k], ny += dy[k];

					if(board[nx][ny] == '#') nx -= dx[k], ny -= dy[k];
					if(!check[nx][ny]) {
						check[nx][ny] = true;
						q.push({nx,ny});
					}
				}
			}
		}
	}
	
	for(int x = 0; x < N; x++) {
		for(int y = 0; y < M; y++) {
			if(!check[x][y] && board[x][y] == '.') cout << 'P';
			else cout << board[x][y];
		}
		cout << '\n';
	}
	
	return 0;
}
