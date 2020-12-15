/* reference: https://jaimemin.tistory.com/1285 */

#include <iostream>
#include <vector>
#include <cstring>

#define sz(x) (int)(x.size())
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e2;

int N, M, K;
string a[MAX];
string target;
vector<pii> start;
int d[MAX][MAX][81];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

bool chk(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

int go(int x, int y, int L) {
	if(L == sz(target)) return 1;
	
	int& ret = d[x][y][L];
	if(ret != -1) return ret;
	ret = 0;
	
	for(int k = 0; k < 4; k++) {
		int nx = x, ny = y;
		for(int i = 0; i < K; i++) {
			nx += dx[k];
			ny += dy[k];
			
			if(!chk(nx, ny)) break;
			if(a[nx][ny] == target[L]) ret += go(nx, ny, L + 1);
		}
	}
	
	return ret;
}

int main() {
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; i++) cin >> a[i];
	cin >> target;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(a[i][j] == target[0]) start.push_back({i, j});
		}
	}
	
	memset(d, -1, sizeof(d));
	int ans = 0;
	for(auto& p : start) {
		int x = p.fi;
		int y = p.sc;
		
		ans += go(x, y, 1);
	}
	cout << ans << '\n';
	
	return 0;
}
