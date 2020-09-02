#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

const int MAX=251;

int N,M;
int a[MAX][MAX];
bool check[MAX][MAX];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

void bfs(int sx, int sy) {
	queue<pi> q;
	q.push({sx, sy});
	check[sx][sy]=true;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<8; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]==1 && check[nx][ny]==false) {
					check[nx][ny]=true;
					q.push({nx,ny});
				}
			}
		}
	}
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	int ans=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(a[i][j]==1 && check[i][j]==false) {
				bfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
