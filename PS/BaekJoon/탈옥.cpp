#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

vector<vector<int>> bfs(vector<string> &a, int x, int y) {
	int n=a.size();
	int m=a[0].size();
	
	vector<vector<int>> d(n,vector<int>(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) d[i][j]=-1;
	}
	
	deque<pair<int,int>> q;
	q.push_back(make_pair(x,y));
	d[x][y]=0;
	
	while(!q.empty()) {
		tie(x,y)=q.front();
		q.pop_front();
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
			if(d[nx][ny]!=-1) continue;
			if(a[nx][ny]=='*') continue;
			if(a[nx][ny]=='#') {
				d[nx][ny]=d[x][y]+1;
				q.push_back(make_pair(nx,ny));
			} else {
				d[nx][ny]=d[x][y];
				q.push_front(make_pair(nx,ny));
			}
		}
	}
	
	return d;
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n,m;
		cin>>n>>m;
		
		vector<string> a(n+2);
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			a[i] = "." + a[i] + ".";
		}
		
		n+=2;
		m+=2;
		for(int j=0; j<m; j++) {
			a[0]+=".";
			a[n-1]+=".";
		}
		
		vector<vector<int>> d0=bfs(a,0,0);
		
		int x1,y1,x2,y2;
		x1=y1=x2=y2=-1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]=='$') {
					if(x1==-1) {
						x1=i;
						y1=j;
					} else {
						x2=i;
						y2=j;
					}
				}
			}
		}
		
		vector<vector<int>> d1=bfs(a,x1,y1);
		vector<vector<int>> d2=bfs(a,x2,y2);
		int ans=n*m;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(a[i][j]=='*') continue;
				int cur=d0[i][j]+d1[i][j]+d2[i][j];
				
				if(a[i][j]=='#') cur-=2;
				if(ans>cur) ans=cur;
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
