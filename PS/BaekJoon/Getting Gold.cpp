#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=50;

char a[MAX][MAX];
int d[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int N,M;
	cin>>M>>N;
	
	int sx, sy;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='P') {
				sx=i;
				sy=j;
			}
		}
	}
	
	memset(d, -1, sizeof(d));
	queue<pi> q;
	q.push({sx,sy});
	d[sx][sy]=true;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		// check if Trap is nearby
		bool is_trap_nearby=false;
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]=='T') {
					is_trap_nearby=true;
					break;
				}
			}
		}
		
		if(is_trap_nearby==false) {
			for(int k=0; k<4; k++) {
				int nx=dx[k]+x;
				int ny=dy[k]+y;
				
				if(0<=nx && nx<N && 0<=ny && ny<M) {
					if(a[nx][ny]=='#' || a[nx][ny]=='T') continue;
					
					if(d[nx][ny]==-1) {
						d[nx][ny]=1;
						q.push({nx,ny});
					}
				}
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(d[i][j]==1 && a[i][j]=='G') ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
