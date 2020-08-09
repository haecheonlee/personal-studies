#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using pi=pair<int,int>;
using tpl=tuple<int,int,int>;

int N,M;
int a[101][101];
bool check[101][101];
int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={-1,0,1,-1,0,1,-1,1};

void bfs(int sx, int sy) {
	queue<pi> q;
	q.push(make_pair(sx,sy));
	check[sx][sy]=true;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<8; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];

			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]==0) continue;
				if(check[nx][ny]==false && a[x][y]>=a[nx][ny]) {
					check[nx][ny]=true;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int main() {
	cin>>N>>M;
	
	priority_queue<tpl> pq;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			if(a[i][j]>0) pq.push(make_tuple(a[i][j],i,j));	
		}
	}
	
	int ans=0;
	while(!pq.empty()) {
		int h,x,y;
		tie(h,x,y)=pq.top();
		pq.pop();
		
		if(check[x][y]==false) {
			bfs(x,y);
			ans++;	
		}
	}
	cout<<ans;
	
	return 0;
}
