#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m,n;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,-1,1};
int dist[100][100];

void bfs(const vector<string> &vec, int x, int y, int cnt) {
	queue<pair<int,int>> q;
	q.push({x,y});
	dist[x][y]=cnt;
	
	while(!q.empty()) {
		int current_x=q.front().first;
		int current_y=q.front().second;
		q.pop();
		
		for(int k=0; k<8; k++) {
			int nx=current_x+dx[k];
			int ny=current_y+dy[k];
			
			if(0<=nx && nx<m && 0<=ny && ny<n) {
				if(vec[nx][ny]=='@' && dist[nx][ny]==-1) {
					q.push({nx,ny});
					dist[nx][ny]=cnt;
				}
			}
		}
	}
}

int main() {
	while(1) {
		cin>>m>>n;
		if(m==0) break;
		
		vector<string> vec(m);
		for(int i=0; i<m; i++) {
			cin>>vec[i];
			for(int j=0; j<vec[i].size(); j++) {
				dist[i][j]=-1;
			}
		}
		
		int cnt=0;
		for(int i=0; i<m; i++) {
			for(int j=0; j<vec[i].size(); j++) {
				if(vec[i][j]=='@' && dist[i][j]==-1) {
					bfs(vec,i,j,++cnt);
				}
			}
		}
		
		cout<<cnt<<'\n';
	}
	
	return 0;
}

/*
boj.kr/4677

INPUT:
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0

OUTPUT:
0
1
2
2
*/
