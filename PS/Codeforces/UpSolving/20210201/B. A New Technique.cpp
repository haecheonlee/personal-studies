#include <iostream>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 5e2 * 5e2 + 1e2;

pii p[MAX];

void solve() {
	int N, M; cin >> N >> M;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			int x;
			cin >> x;
			
			p[x].sc = j;
		}
	}
	
	for(int i = 1; i <= M; i++) {
		for(int j = 1; j <= N; j++) {
			int x;
			cin >> x;
			
			p[x].fi = j;
		}
	}

	int arr[N + 1][M + 1];
	for(int i = 1; i <= N * M; i++) arr[p[i].fi][p[i].sc] = i;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) cout << arr[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
