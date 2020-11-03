#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3;

int N,M;
char a[MAX][MAX];
int c[MAX][MAX];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

bool is_in_range(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

void print() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cout<<a[i][j]<<' ';
		cout<<'\n';
	}
}

int main() {
	cin>>N>>M;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cin>>a[i][j];
	}
	
	vector<pii> p;
	for(int x = 0; x < N; x++) {
		for(int y = 0; y < M; y++) {
			if(a[x][y] != '.') continue;
			
			for(int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(a[nx][ny] == '.') continue;
				
				if(is_in_range(nx, ny)) {
					c[nx][ny]++;
					if(c[nx][ny] == a[nx][ny] - '0') p.push_back({nx,ny});
				}
			}
		}
	}

	int ans = 0;
	while(!p.empty()) {
		vector<pii> next;
		for(auto& pp : p) {
			int x = pp.first;
			int y = pp.second;

			for(int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if(a[nx][ny] == '.') continue;
				
				if(is_in_range(nx, ny)) {
					c[nx][ny]++;
					if(c[nx][ny] == a[nx][ny] - '0') next.push_back({nx,ny});
				}
			}
			
			a[x][y] = '.';
		}
		
		ans++;
		p = next;
	}
	cout<<ans;

	return 0;
}
