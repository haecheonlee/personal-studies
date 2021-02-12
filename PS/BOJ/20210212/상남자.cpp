#include <iostream>
#include <deque>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 10;

int N, M, L, R;
char board[MAX][MAX];
bool check[MAX][MAX];

bool chk(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

int main() {
	cin >> N >> M >> L >> R;
	
	int sx, sy;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> board[i][j];
			if(board[i][j] == '2') {
				board[i][j] = '0';
				sx = i, sy = j;
			}
		}
	}
	
	deque<pair<pii,pii>> dq;
	dq.push_back({{sx, sy}, {L, R}});
	check[sx][sy] = 1;
	
	while(!dq.empty()) {
		int x = dq.front().fi.fi;
		int y = dq.front().fi.sc;
		int l = dq.front().sc.fi;
		int r = dq.front().sc.sc;
		dq.pop_front();
		
		int nx, ny;
		
		// up
		nx = x - 1, ny = y;
		while(chk(nx, ny) && board[nx][ny] == '0' && !check[nx][ny]) {
			check[nx][ny] = 1;
			dq.push_front({{nx, ny}, {l, r}});
			
			nx = x - 1, ny = y;
		}
		
		// down
		nx = x + 1, ny = y;
		while(chk(nx, ny) && board[nx][ny] == '0' && !check[nx][ny]) {
			check[nx][ny] = 1;
			dq.push_front({{nx, ny}, {l, r}});
		}
		
		// left
		if(l - 1 >= 0) {
			nx = x, ny = y - 1;
			if(chk(nx, ny) && board[nx][ny] == '0' && !check[nx][ny]) {
				check[nx][ny] = 1;
				dq.push_back({{nx, ny}, {l - 1, r}});
			}
		}
		
		// right
		if(r - 1 >= 0) {
			nx = x, ny = y + 1;
			if(chk(nx, ny) && board[nx][ny] == '0' && !check[nx][ny]) {
				check[nx][ny] = 1;
				dq.push_back({{nx, ny}, {l, r - 1}});
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < M; j++) 
			ans += check[i][j];
	cout << ans << '\n';
	
	return 0;
}
