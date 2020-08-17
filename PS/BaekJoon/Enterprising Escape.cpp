#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using ll=long long;
using tpl=tuple<int,int,int>;

const ll INF=1e13;

int N,W,H;
int t[26];
ll d[1001][1001];
char a[1001][1001];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy) {
	priority_queue<tpl> q;
	q.push({0,sx,sy});
	
	while(!q.empty()) {
		int cost,x,y;
		tie(cost,x,y)=q.top();
		cost=-cost;
		q.pop();
		
		if(d[x][y]<cost) continue;
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			int min=t[a[nx][ny]-'A'];
			
			if(0<=nx && nx<H && 0<=ny && ny<W) {
				if(d[nx][ny]>d[x][y]+min) {
					d[nx][ny]=d[x][y]+min;
					q.push({-d[nx][ny],nx,ny});
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	while(T--) {
		cin>>N>>W>>H;
		
		for(int i=0; i<N; i++) {
			char cls;
			int min;
			
			cin>>cls>>min;
			t[cls-'A']=min;
		}
		
		int sx=-1, sy=-1;
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				cin>>a[i][j];
				if(a[i][j]=='E') {
					sx=i;
					sy=j;
					d[i][j]=0;
				} else {
					d[i][j]=INF;
				}
			}
		}
		
		// run graph
		bfs(sx,sy);
		
		// answer
		int ans=-1;
		for(int i=0; i<W; i++) {
			int up=d[0][i];
			if(ans==-1 || ans>up) ans=up;
			
			int down=d[H-1][i];
			if(ans==-1 || ans>down) ans=down;
		}
		
		for(int i=0; i<H; i++) {
			int left=d[i][0];
			if(ans==-1 || ans>left) ans=left;
			
			int right=d[i][W-1];
			if(ans==-1 || ans>right) ans=right;
		}
		cout<<ans<<'\n';
	}

	return 0;
}
