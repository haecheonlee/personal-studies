#include <iostream>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

const int MAX = 21;

typedef pair<int,int> pii;

int N, M, a, aa, b, bb;
char board[MAX][MAX];
int d[MAX][MAX][MAX][MAX];
int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool chk(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M && board[x][y] == '.';
}

int main() {
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> board[i][j];
			
			if(board[i][j] == 'A') board[i][j] = '.', a = i, aa = j;
			else if(board[i][j] == 'B') board[i][j] = '.', b = i, bb = j;
		}
	}
	
	memset(d, -1, sizeof(d));
	queue<pair<pii, pii>> q;
	q.push({{a, aa}, {b, bb}});
	d[a][aa][b][bb] = 0;
	
	while(!q.empty()) {
		int ax = q.front().fi.fi, ay = q.front().fi.sc;
		int bx = q.front().sc.fi, by = q.front().sc.sc;
		q.pop();
		
		for(int k = 0; k < 9; k++) {
			int nax = ax + dx[k], nay = ay + dy[k];
			
			if(!chk(nax, nay)) continue;
			for(int kk = 0; kk < 9; kk++) {
				int nbx = bx + dx[kk], nby = by + dy[kk];
				
				if(!chk(nbx, nby) || (nax == bx && nay == by && nbx == ax && nby == ay) || (nbx == nax && nby == nay)) 
					continue;
					
				if(d[nax][nay][nbx][nby] == -1) {
					d[nax][nay][nbx][nby] = d[ax][ay][bx][by] + 1;
					q.push({{nax, nay}, {nbx, nby}});
				}
			}
		}
	}
	
	cout << d[b][bb][a][aa] << '\n';
	
	return 0;
}
