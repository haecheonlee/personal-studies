#include <iostream>
#include <queue>

using namespace std;

int n,m,t;
int a[101][101];
int d1[101][101];
int d2[101][101];
int dx[]={1,-1,0,0}; // up down right left
int dy[]={0,0,1,-1}; // up down right left
int dx2[]={0,1}; // down right
int dy2[]={1,0}; // down right

int main() {
	cin>>n>>m>>t;

	int weapon_x, weapon_y;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) { 
			cin>>a[i][j];
			d1[i][j]=-1;d2[i][j]=-1;
			
			if(a[i][j]==2) {
				weapon_x=i;
				weapon_y=j;
			}
		}
	}

	// check from weapon_x, weapon_y
	queue<pair<int,int>> q;
	q.push({weapon_x,weapon_y});
	d1[weapon_x][weapon_y]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<2; k++) {
			int nx=dx2[k]+x;
			int ny=dy2[k]+y;
		
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(d1[nx][ny]==-1) {
					d1[nx][ny]=d1[x][y]+1;
					q.push({nx,ny});
				}
			}
		}
	}
	
	
	// check from hero(0,0)
	q=queue<pair<int,int>>();
	q.push({0,0});
	d2[0][0]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(d2[nx][ny]==-1 && a[nx][ny]!=1) {
					d2[nx][ny]=d2[x][y]+1;
					q.push({nx,ny});
				}
			}
		}
	}

	int reached_time;
	if(d2[weapon_x][weapon_y]==-1) {
		// weapon not reached
		reached_time=d2[n-1][m-1];
	} else {
		// weapon reached
		int with_weapon=d1[n-1][m-1]+d2[weapon_x][weapon_y];
		int without_weapon=d2[n-1][m-1];
		
		if(without_weapon==-1) reached_time=with_weapon;
		else reached_time=min(with_weapon,without_weapon);
	}
	
	if(reached_time==-1) cout<<"Fail";
	else if(reached_time>t) cout<<"Fail";
	else cout<<reached_time;
	
	return 0;
}

/*
INPUT:
6 6 16
0 0 0 0 1 1
0 0 0 0 0 2
1 1 1 0 1 0
0 0 0 0 0 0
0 1 1 1 1 1
0 0 0 0 0 0

OUTPUT:
10
*/
