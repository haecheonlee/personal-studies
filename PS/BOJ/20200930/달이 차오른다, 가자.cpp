#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
using tpl=tuple<int,int,int>;

const int MAX=50;

char a[MAX][MAX];
int d[MAX][MAX][65];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int N,M;
	cin>>N>>M;
	
	int sx, sy;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			if(a[i][j]=='0') sx=i, sy=j;
		}
	}
	
	memset(d, -1, sizeof(d));
	queue<tpl> q;
	q.push({sx,sy,0});
	d[sx][sy][0]=0;
	int ans=-1;
	while(!q.empty()) {
		int x=get<0>(q.front());
		int y=get<1>(q.front());
		int key=get<2>(q.front());
		q.pop();
		
		if(a[x][y]=='1') {
			ans=d[x][y][key];
			break;
		}
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]=='#') continue;
				
				int next_key=key;
				if(a[nx][ny]>='a' && a[nx][ny]<='f') {
					next_key|=(1<<(a[nx][ny]-'a'));	
				}
				
				if(a[nx][ny]>='A' && a[nx][ny]<='F') {
					if(!(key & (1<<(a[nx][ny]-'A')))) continue; 
				}
				
				if(d[nx][ny][next_key]==-1) {
					d[nx][ny][next_key]=d[x][y][key]+1;
					q.push({nx, ny, next_key});
				}
			}
		}
	}
	cout<<ans;

	return 0;
}
