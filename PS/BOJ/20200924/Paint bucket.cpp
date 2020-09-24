#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3;

char a[MAX][MAX];
bool check[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	int sx, sy;
	char color;
	cin>>sx>>sy>>color;
	char chosen=a[sx][sy];
	
	queue<pi> q;
	q.push({sx,sy});
	a[sx][sy]=color;
	check[sx][sy]=true;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(check[nx][ny]==false && a[nx][ny]==chosen) {
					check[nx][ny]=true;
					a[nx][ny]=color;
					q.push({nx,ny});
				}
			}
		}
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cout<<a[i][j];
		cout<<'\n';
	}
	
	return 0;
}
