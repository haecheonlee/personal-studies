#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 2e3 + 3e2;

int a[MAX][MAX];
int d[MAX][MAX];
int dx[] = {0, 1};
int dy[] = {1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	for(int i =0; i < N; i++) {
		for(int j = 0; j < N; j++) cin >> a[i][j];
	}

	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	for(int x = 0; x < N; x++) {
		for(int y = 0; y < N; y++) {
			if(d[x][y] == -1) continue;
			
			for(int k = 0; k < 2; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if(0 <= nx && nx < N && 0 <= ny && ny < N) {
					int sum = d[x][y] + (a[x][y] > a[nx][ny] ? 0 : a[nx][ny] -  a[x][y] + 1);
					if(d[nx][ny] == -1 || d[nx][ny] > sum) d[nx][ny] = sum;
				}
			}
		}
	}

	cout << d[N - 1][N -1];

	return 0;
}
