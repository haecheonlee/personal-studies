#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

char a[200][200];
int d[200][200];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main() {
	int N,M;
	cin>>N>>M;
	
	queue<pi> q;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			
			d[i][j]=-1;
			if(a[i][j]=='1') {
				q.push({i,j});
				d[i][j]=0;
			}
		}
	}
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push({nx,ny});
				}
			}
		}
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cout<<d[i][j]<<' ';
		cout<<'\n';
	}
	
	return 0;
}
