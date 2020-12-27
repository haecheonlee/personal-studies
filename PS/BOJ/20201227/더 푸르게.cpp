#include <iostream>
#include <vector>

#define sz(x) (int)(x.size())
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

int N, M, ans;
char board[10][10];
vector<pair<pii,char>> a;

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};	// 0 ~ 3: adjacent | 4 ~ 7: diagonal
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dxk[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dyk[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool chk(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}

bool King(int x, int y) {
	for(int k = 0; k < 8; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if(chk(nx, ny) && board[nx][ny] != 'E') return false;
	}
	
	return true;
}

bool Queen(int x, int y) {
	for(int k = 0; k < 8; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		
		while(chk(nx, ny)) {
			if(board[nx][ny] != 'E') return false;
			nx += dx[k], ny += dy[k];
		}
	}

	return true;
}

bool Bishop(int x, int y) {
	for(int k = 4; k < 8; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		
		while(chk(nx, ny)) {
			if(board[nx][ny] != 'E') return false;
			nx += dx[k], ny += dy[k];
		}
	}
	
	return true;
}

bool Rook(int x, int y) {
	for(int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		
		while(chk(nx, ny)) {
			if(board[nx][ny] != 'E') return false;
			nx += dx[k], ny += dy[k];
		}
	}
	
	return true;
}

bool Knight(int x, int y) {
	for(int k = 0; k < 8; k++) {
		int nx = x + dxk[k], ny = y + dyk[k];
		if(chk(nx, ny) && board[nx][ny] != 'E') return false;
	}
	
	return true;
}

void go(int i) {
	if(i >= a.size()) {
		int cnt = 0;
		
		for(auto& pp : a) {
			int x = pp.fi.fi, y = pp.fi.sc;
			char piece = pp.sc;

			if(board[x][y] == 'E') continue;
			
			cnt++;
			
			if(piece == 'K') {
				if(!King(x, y)) cnt = -1;
			} else if(piece == 'Q') {
				if(!Queen(x, y)) cnt = -1;
			} else if(piece == 'R') {
				if(!Rook(x, y)) cnt = -1;
			} else if(piece == 'B') {
				if(!Bishop(x, y)) cnt = -1;
			} else if(piece == 'N') {
				if(!Knight(x, y)) cnt = -1;
			}
			
			if(cnt == -1) break;
		}
		
		if(cnt != -1) ans = max(ans, cnt);
		
		return;
	}
	
	// skip
	go(i + 1);
	
	// take
	int x = a[i].fi.fi, y = a[i].fi.sc;
	char piece = a[i].sc;
	
	board[x][y] = 'E';
	go(i + 1);
	board[x][y] = piece;
}

int main() {
	string start, end;
	
	while(cin >> start) {
		// reset
		ans = 0;
		a.clear();

		cin >> M >> N;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				cin >> board[i][j];
				if(board[i][j] != 'E') a.push_back({{i, j}, board[i][j]});
			}
		}
		
		go(0);
		
		cout << "Minimum Number of Pieces to be removed: " << sz(a) - ans << '\n';
		
		cin >> end;
	}
	
	return 0;
}
