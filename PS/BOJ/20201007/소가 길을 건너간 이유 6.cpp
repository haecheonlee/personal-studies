/* reference: https://justicehui.github.io/usaco/2019/06/22/BOJ14466/ */

#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e2+1;

int N,K,R;
set<pi> g[MAX][MAX];
bool check[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int x, int y) {
	check[x][y]=true;
	
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(1<=nx && nx<=N && 1<=ny && ny<=N) {
			if(check[nx][ny]==false && g[x][y].count({nx,ny})==0) {
				dfs(nx,ny);
			}
		}
	}
}

int main() {
	cin>>N>>K>>R;
	
	for(int i=0; i<R; i++) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		
		g[a][b].insert({c,d});
		g[c][d].insert({a,b});
	}
	
	vector<pi> a(K);
	for(int i=0; i<K; i++) cin>>a[i].first>>a[i].second;
	
	int ans=0;
	for(int i=0; i<K; i++) {
		memset(check, false, sizeof(check));
		dfs(a[i].first, a[i].second);
		
		for(int j=i+1; j<K; j++) {
			if(check[a[j].first][a[j].second]==false) {
				ans++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
