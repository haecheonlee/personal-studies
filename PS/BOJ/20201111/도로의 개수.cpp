#include <iostream>
#include <vector>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1e2 + 1;

int N, M, K;
ll d[MAX][MAX];
bool check[MAX][MAX][2];
int dx[] = {0, 1};
int dy[] = {1, 0};

ll go(int x, int y) {
	if(x == N && y == M) return 1;

	ll& ret = d[x][y];
	if(ret != -1) return ret;
	ret = 0;

	for(int k = 0; k < 2; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		
		if(nx <= N && ny <=M) {
			if(!check[x][y][k]) ret += go(nx, ny);
		}
	}

	return ret;
}

int main() {
	cin >> M >> N >> K;

	for(int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		check[min(b,d)][min(a,c)][((a - c == 0) ? 1 : 0)] = true;
	}

	memset(d, -1, sizeof(d));
	cout << go(0, 0) << '\n';
	
	return 0;
}
