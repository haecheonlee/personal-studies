#include <iostream>

using namespace std;

const int MAX = 5e2 + 10;

int N, M;
char board[MAX][MAX];
bool check[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool chk(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;	
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> board[i][j];
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(board[i][j] == '*') {
				bool is_good = 1;
				for(int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if(!chk(nx, ny) || board[nx][ny] != '*') {
						is_good = 0;
						break;
					}
				}
				
				if(is_good) {
					for(int k = 0; k < 4; k++) {
						int nx = i, ny = j;
						while(chk(nx, ny) && board[nx][ny] == '*') {
							check[nx][ny] = 1;
							nx += dx[k], ny += dy[k];
						}
					}
					
					for(int x = 0; x < N; x++) {
						for(int y = 0; y < M; y++) {
							if(board[x][y] == '*' && !check[x][y]) {
								cout << "NO" << '\n';
								return 0;
							}
						}
					}
					
					cout << "YES" << '\n';
					return 0;
				}
			}
		}
	}
	
	cout << "NO" << '\n';
	
	return 0;
}
