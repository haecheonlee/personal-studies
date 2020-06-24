#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

int N,M;
string a[100];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool check[100][100];
int ans[2]={0,0};

int convert(char c) {
	if(c=='W') return 0;
	if(c=='B') return 1;
}

void bfs(int sx, int sy) {
	char c=a[sx][sy];
	
	queue<pi> q;
	q.push(make_pair(sx,sy));
	check[sx][sy]=true;	
	
	int total=1;
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(check[nx][ny]==false && a[nx][ny]==c) {
					q.push(make_pair(nx,ny));
					
					check[nx][ny]=true;
					total++;
				}	
			}
		}
	}
	
	ans[convert(c)]+=total*total;
}

int main() {
	cin>>M>>N;
	
	for(int i=0; i<N; i++) cin>>a[i];
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(check[i][j]==false) bfs(i,j);
		}
	}
	
	for(int i=0; i<2; i++) cout<<ans[i]<<" ";
	
	return 0;
}
