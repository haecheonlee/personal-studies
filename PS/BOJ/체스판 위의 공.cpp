/* reference: https://hsdevelopment.tistory.com/514 */

#include <iostream>

using namespace std;

const int MAX = 5e2 + 1;
const int INF = 3e5 + 1;

int a[MAX][MAX];
int p[MAX * MAX], ans[MAX * MAX];
int dx[] = {-1,-1,-1,0,0,0,1,1,1};
int dy[] = {-1,0,1,-1,0,1,-1,0,1};

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cin>>a[i][j];
	}
	
	for(int x = 0; x < N; x++) {
		for(int y = 0; y < M; y++) {
			int mn = INF;
			int px = 0, py = 0;
			
			for(int k = 0; k < 9; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if(0 <= nx && nx < N && 0 <= ny && ny < M) {
					if(mn > a[nx][ny]) {
						mn = a[nx][ny];
						px = nx, py = ny;
					}
				}
			}
			
			p[x * M + y] = px * M + py;
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) ans[Find(i * M + j)]++;
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cout<<ans[i * M + j]<<' ';
		cout<<'\n';
	}
	
	return 0;
}
