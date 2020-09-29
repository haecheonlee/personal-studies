#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e2;

int a[MAX][MAX];
int d[MAX][MAX];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	int ans=0;
	while(1) {
		memset(d, 0, sizeof(d));
		
		queue<pi> q;
		q.push({0,0});
		d[0][0]=1;
		
		while(!q.empty()) {
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			
			for(int k=0; k<4; k++) {
				int nx=x+dx[k];
				int ny=y+dy[k];
				
				if(0<=nx && nx<N && 0<=ny && ny<M) {
					if(a[nx][ny]==0) {
						if(d[nx][ny]==0) {
							d[nx][ny]=1;
							q.push({nx,ny});
						}
					} else {
						d[nx][ny]++;
					}
				}
			}
		}
		
		bool is_changed=false;
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(a[i][j]==1 && d[i][j]>=2) {
					a[i][j]=0;
					is_changed=true;
				}
			}
		}
		
		if(is_changed==false) break;
		ans++;
	}
	cout<<ans;
	
	return 0;
}
