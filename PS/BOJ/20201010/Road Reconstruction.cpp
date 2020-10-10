#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3+1;

int a[MAX][MAX];
int d[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	
	if(a[0][0]==-1 || a[N-1][M-1]==-1) {
		cout<<-1;
	} else {
		memset(d, -1, sizeof(d));

		priority_queue<pair<int,pi>> q;
		q.push({-a[0][0],{0,0}});
		d[0][0]=a[0][0];
		
		while(!q.empty()) {
			int cost=-q.top().first;
			int x=q.top().second.first;
			int y=q.top().second.second;
			q.pop();
			
			if(d[x][y]<cost) continue;
			for(int k=0; k<4; k++) {
				int nx=x+dx[k];
				int ny=y+dy[k];
				
				if(0<=nx && nx<N && 0<=ny && ny<M) {
					if(a[nx][ny]==-1) continue;
					if(d[nx][ny]==-1 || d[nx][ny]>cost+a[nx][ny]) {
						d[nx][ny]=cost+a[nx][ny];
						q.push({-d[nx][ny], {nx,ny}});
					}
				}
			}
		}
		
		cout<<d[N-1][M-1];
	}
	
	return 0;
}
