#include <iostream>
#include <queue>

using namespace std;

int n,m;
int a[300][300];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	
	vector<pair<int,int>> vec;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) { 
			cin>>a[i][j];
			if(a[i][j]!=0) vec.push_back({i,j});	
		}
	}
	
	int time=0;
	while(1) {
		if(vec.size()==0) {
			cout<<0;
			return 0;
		}
		
		int dist[n][m];
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				dist[i][j]=0;
			}
		}
		for(int i=0; i<vec.size(); i++) dist[vec[i].first][vec[i].second]=-1;

		int cnt=0;
		for(int i=0; i<vec.size(); i++) {
			if(dist[vec[i].first][vec[i].second]==-1) {
				queue<pair<int,int>> q;
				q.push({vec[i].first, vec[i].second});
				dist[vec[i].first][vec[i].second]=cnt+1;
				
				while(!q.empty()) {
					int x=q.front().first;
					int y=q.front().second;
					q.pop();
					
					for(int k=0; k<4; k++) {
						int nx=x+dx[k];
						int ny=y+dy[k];
						
						if(0<=nx && nx<n && 0<=ny && ny<m) {
							if(a[nx][ny]!=0 && dist[nx][ny]==-1) {
								q.push({nx,ny});
								dist[nx][ny]=dist[x][y];	
							}
						}
					}
				}
				
				cnt+=1;
			}
		}
		
		if(cnt>=2) {
			cout<<time;	
			return 0;
		}
		
		// metling icebergs
		vector<int> l(vec.size());
		for(int i=0; i<vec.size(); i++) {
			int x=vec[i].first;
			int y=vec[i].second;
			
			for(int k=0; k<4; k++) {
				int nx=x+dx[k];
				int ny=y+dy[k];
				
				if(0<=nx && nx<n && 0<=ny && ny<m) {
					if(a[nx][ny]==0) {
						l[i]++;
					}
				}
			}
		}
		
		for(int i=0; i<vec.size(); i++) {
			int x=vec[i].first;
			int y=vec[i].second;
			
			a[x][y]=((a[x][y]-l[i]<=0) ? 0 : a[x][y]-l[i]);
			if(a[x][y]==0) {
				vec.erase(vec.begin()+i);
				l.erase(l.begin()+i);
				i-=1;
			}
		}
		
		time++;
	}
		
	return 0;
}

/*
boj.kr/2573

INPUT:
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0

OUTPUT:
2
*/
