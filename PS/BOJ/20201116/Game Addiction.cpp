#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX = 31;

int H, N;
ll d[MAX][MAX][MAX * MAX];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int dist = -1;

ll go(int x, int y, int cost) {
	if(cost > dist) return 0;
	if(x == H && y == H) {
		return (cost == dist);
	}

	ll& ret = d[x][y][cost];
	if(ret != -1) return ret;
	ret = 0;

	for(int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if(0 <= nx && nx < MAX && 0 <= ny && ny < MAX) {
			if(ny <= nx) ret += go(nx, ny, cost + 1);
		}
	}

	return ret;
}

int main() {
	cin >> H >> N;

	dist = abs(H - N) + abs(H - N);

	memset(d, -1, sizeof(d));
	cout << go(N, N, 0);

	return 0;
}
