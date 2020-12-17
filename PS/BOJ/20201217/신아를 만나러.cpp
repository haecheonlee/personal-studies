#include <iostream>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;

int d[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
	int X, Y, N;
	cin >> X >> Y >> N;
	
	X += 500, Y += 500;
	
	memset(d, -1, sizeof(d));
	for(int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		
		x += 500, y += 500;
		d[x][y] = -2;
	}
	
	queue<pii> q;
	q.push({500, 500});
	d[500][500] = 0;
	while(!q.empty()) {
		int x = q.front().fi;
		int y = q.front().sc;
		q.pop();
		
		if(x == X && y == Y) {
			cout << d[X][Y] << '\n';
			break;
		}
		
		for(int k = 0; k < 4; k++) {
			int nx = dx[k] + x;
			int ny = dy[k] + y;
			
			if(0 <= nx && nx <= 1000 && 0 <= ny && ny <= 1000) {
				if(d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push({nx, ny});
				}
			}
		}
	}

	return 0;
}
