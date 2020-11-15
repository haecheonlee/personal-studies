#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e2 + 1;

char a[MAX][MAX];
vector<pii> p;
int now[MAX][MAX], after[MAX][MAX];
int dx[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int main() {
	int N, M;
	cin >> N >> M;

	int sx, sy;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> a[i][j];

			if(a[i][j] == 'I') {
				sx = i;
				sy = j;
			} else if(a[i][j] =='R') {
				p.push_back({i, j});
				now[i][j]++;
			}
		}
	}

	string s;
	cin >> s;

	int moved = 0;
	for(auto& move : s) {
		int k = move - '0' - 1;
		
		// 1
		sx += dx[k];
		sy += dy[k];
		moved++;

		// 2
		if(now[sx][sy]) {
			cout << "kraj " << moved;
			return 0;
		}
  
		// 3
		memset(after, 0, sizeof(after));
		set<pii> destroy;
		for(auto& pp : p) {
			int kk = -1, dist = -1;

			for(int i = 0; i < 9; i++) {
				int pnx = pp.first + dx[i];
				int pny = pp.second + dy[i];

				if(0 <= pnx && pnx < N && 0 <= pny && pny < M) {
					int d = abs(sx - pnx) + abs(sy - pny);
					if(dist == -1 || dist > d) dist = d, kk = i;
				}
			}

			pp.first += dx[kk], pp.second += dy[kk];
			after[pp.first][pp.second]++;
			if(after[pp.first][pp.second] >= 2) destroy.insert({pp.first, pp.second});
		}
		swap(now, after);

		// 4
		if(now[sx][sy]) {
			cout << "kraj " << moved;
			return 0;
		}

		// 5
		for(auto it : destroy) {
			p.erase(remove(p.begin(), p.end(), make_pair(it.first, it.second)), p.end());
		}
	}

	vector<vector<char>> ans(N, vector<char>(M, '.'));

	ans[sx][sy] = 'I';
	for(auto& pp : p) ans[pp.first][pp.second] = 'R';

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cout << ans[i][j];
		cout << '\n';
	}

	return 0;
}
