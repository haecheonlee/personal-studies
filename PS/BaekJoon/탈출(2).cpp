#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <iomanip>

using namespace std;

int n,m;
char a[51][51];
int mole[51][51];
int water[51][51];
vector<pair<int,int>> water_list;
vector<pair<int,int>> mole_list;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	cin>>n>>m;
	
	int s_x,s_y;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='*') water_list.push_back(make_pair(i,j));
			if(a[i][j]=='S') mole_list.push_back(make_pair(i,j));
			if(a[i][j]=='D') s_x=i,s_y=j;
			
			mole[i][j]=-1;
			water[i][j]=-1;
		}
	}
	
	// water 
	queue<tuple<int,int>> q;
	for(auto now : water_list) {
		water[now.first][now.second]=0;
		q.push(make_tuple(now.first,now.second));
	}
	
	while(!q.empty()) {
		int x,y;
		tie(x,y)=q.front();
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(water[nx][ny]==-1 && a[nx][ny]!='X' && a[nx][ny]!='D') {
					water[nx][ny]=water[x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	
	// mole
	for(auto now : mole_list) {
		mole[now.first][now.second]=0;
		q.push(make_pair(now.first, now.second));
	}
	
	while(!q.empty()) {
		int x,y;
		tie(x,y)=q.front();
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(mole[nx][ny]==-1 && (water[nx][ny]==-1 || water[nx][ny]>mole[x][y]+1) && a[nx][ny]!='X' && a[nx][ny]!='*') {
					mole[nx][ny]=mole[x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	
	if(mole[s_x][s_y]==-1) cout<<"KAKTUS";
	else cout<<mole[s_x][s_y];
	
	return 0;
}

/*
INPUT:
3 3
D.*
...
.S.

OUTPUT:
3
*/
