/* reference: https://yabmoons.tistory.com/117 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

const int N = 5;
const int MAX = N * N;

int ans;
vector<int> list;
char board[N][N];
bool check[MAX], visited[MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool bfs() {
	memset(check, false, sizeof(check));


	queue<int> q;
	q.push(list[0]);
	check[list[0]] = true;
	int found = 1;

	while(!q.empty()) {
		int p = q.front();
		q.pop();

		int x = p / N, y = p % N;
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if(0 <= nx && nx < N && 0 <= ny && ny < N) {
				int np = nx * N + ny;
				if(visited[np] && !check[np]) {
					check[np] = true;
					q.push(np);
					found++;
				}
			}
		}
	}

	return found == 7;
}

bool chk() {	 
	int cnt = 0;
	for(auto& p : list) cnt += (board[p / N][p % N] == 'S');

	return bfs() && cnt >= 4;
}

void go(int idx) {
	if(sz(list) == 7) {
		if(chk()) ans++;
		return;
	}

	for(int i = idx; i < MAX; i++) {
		visited[i] = 1;
		list.push_back(i);
		go(i + 1);
		visited[i] = 0;
		list.pop_back();
	}
}

int main() {
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < N; j++) cin >> board[i][j];

	go(0);
	cout << ans << '\n';

	return 0;
}
