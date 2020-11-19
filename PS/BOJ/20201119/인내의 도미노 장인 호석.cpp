#include <iostream>

using namespace std;

const int MAX = 1e2 + 1;

int N, M, R;
int a[MAX][MAX];
bool status[MAX][MAX];	//	up: 0, down: 1

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans = 0;

int convert(char dir) {
	if(dir == 'E') return 0;
	if(dir == 'W') return 1;
	if(dir == 'S') return 2;
	if(dir == 'N') return 3;
	
	return -1;
}

void attack(int x, int y, char dir) {
	int k = convert(dir);
	
	int domino = 0, idx = 0;
	while(x >= 1 && x <= N && y >= 1 && y <= M && idx <= domino) {
		if(!status[x][y]) {
			ans++;
			domino = max(domino, idx + a[x][y] - 1);
		}
		
		status[x][y] = 1;
		x += dx[k], y += dy[k];
		idx++;
	}
}

void defence(int x, int y) {
	status[x][y] = 0;
}

int main() {
	cin >> N >> M >> R;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) cin >> a[i][j];
	}

	while(R--) {
		int x, y;
		char dir;

		cin >> x >> y >> dir;
		attack(x, y, dir);

		cin>> x >> y;
		defence(x, y);
	}
	
	cout << ans << '\n';
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			cout << (status[i][j] ? 'F' : 'S') << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
