#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;
typedef pair<int,int> PI;

int n,m;
int a[51][51];
int d[51][51];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<PI> list;
int ans=-1;

void bfs() {
	memset(d,-1,sizeof(d));
	queue<PI> q;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(a[i][j]==2) {
				d[i][j]=0;
				q.push(make_pair(i,j));
			}
		}
	}

	while(!q.empty()) {
		int x,y;
		tie(x,y)=q.front();
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<n) {
				if(a[nx][ny]==1) continue;
				if(d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push(make_pair(nx,ny));	
				}
			}
		}
	}
	
	int mn=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(a[i][j]!=1) {
				mn=max(mn,d[i][j]);
				if(d[i][j]==-1) return;
			}
		}
	}
	
	if(ans==-1 || ans>mn) {
		ans=mn;	
	}
}

void go(int index, int cnt) {
	if(index==list.size()) {
		if(cnt==m) bfs();
	} else {
		int x,y;
		tie(x,y)=list[index];
		a[x][y]=2;
		go(index+1,cnt+1);
		a[x][y]=0;
		go(index+1,cnt);
	}
}

int main() {
	cin>>n>>m;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>a[i][j];
			if(a[i][j]==2) {
				a[i][j]=0;
				list.push_back(make_pair(i,j));
			}
		}
	}
	
	go(0,0);
	cout<<ans;

	return 0;
}

/*
INPUT:
7 3
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 0 0 2

OUTPUT:
5
*/
