#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

const int MAX=250;

int N,M;
char a[MAX][MAX];
pi group[MAX*MAX];
int group_num=0;
bool check[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy) {
	queue<pi> q;
	q.push({sx,sy});
	check[sx][sy]=true;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		if(a[x][y]=='v') group[group_num].first++;
		else if(a[x][y]=='k') group[group_num].second++;
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]=='#') continue;
				if(check[nx][ny]==false) {
					check[nx][ny]=true;
					q.push({nx,ny});
				}
			}
		}
	}
	
	group_num++;
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(a[i][j]=='#') continue;
			if(check[i][j]==false) bfs(i,j);
		}
	}
	
	pi ans={0,0};
	for(int i=0; i<group_num; i++) {
		if(group[i].first==0 && group[i].second==0) continue;
		if(group[i].first<group[i].second) ans.second+=group[i].second;
		else ans.first+=group[i].first;
	}
	cout<<ans.second<<' '<<ans.first;

	return 0;
}
