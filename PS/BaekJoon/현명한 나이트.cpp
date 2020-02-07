#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool check[500][500];
int dist[500][500]{0};
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};
int n;

void bfs(int x, int y) {
	check[x][y]=true;
	queue<pair<int,int>> q;
	q.push({x,y});
	
	while(!q.empty()) {
		int current_x=q.front().first;
		int current_y=q.front().second;
		q.pop();
		
		for(int k=0; k<8; k++) {
			int nx=current_x+dx[k];
			int ny=current_y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<n) {
				if(check[nx][ny]==false && dist[nx][ny]==0) {
					q.push({nx,ny});
					check[nx][ny]=true;
					dist[nx][ny]=dist[current_x][current_y]+1;
				}
			}
		}
	}
}

int main() {
	int m,kx,ky,x,y;
	cin>>n>>m>>kx>>ky;

	vector<pair<int,int>> vec;
	while(m--) {
		cin>>x>>y;
		vec.push_back({x-1,y-1});
	}

	bfs(kx-1,ky-1);

	for(int i=0; i<vec.size(); i++) 
		cout<<dist[vec[i].first][vec[i].second]<<" ";
	

	return 0;
}

/*
boj.kr/18404

INPUT:
5 3
2 4
3 2
3 5
4 5

OUTPUT:
1 2 1
*/
