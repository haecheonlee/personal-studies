#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

int N,M;
int a[501][501];
int sum[15000];
bool check[501][501];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy, int grp) {
	queue<pi> q;
	q.push(make_pair(sx,sy));
	check[sx][sy]=true;
	
	int cnt=1;
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(check[nx][ny]==false && a[nx][ny]==1) {
					cnt++;
					check[nx][ny]=true;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	
	sum[grp]=cnt;
}

int main() {
	cin>>N>>M;

	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	int ans=0;
	int grp=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(check[i][j]==false && a[i][j]==1) {
				bfs(i,j,grp);
				ans=max(ans,sum[grp]);
				grp++;
			}
		}
	}
	
	cout<<grp<<endl;
	cout<<ans;

	return 0;
}
