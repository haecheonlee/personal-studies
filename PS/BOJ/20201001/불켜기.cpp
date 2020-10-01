#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e2+1;

int N,M;
vector<pi> a[MAX][MAX];
int d[MAX][MAX];
bool possible[MAX][MAX], check[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int board[MAX][MAX];

void go(int x, int y) {
	check[x][y]=true;
	
	// possible visiting grid
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(1<=nx && nx<=N && 1<=ny && ny<=N) possible[nx][ny]=true;
	}
	
	// turning on light
	for(auto& p : a[x][y]) {
		int nx=p.first;
		int ny=p.second;
		
		check[nx][ny]=true;		
	}
}

int main() {
	cin>>N>>M;

	for(int i=0; i<M; i++) {
		int sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		a[sx][sy].push_back({ex,ey});
	}
	
	check[1][1]=possible[1][1]=true;
	for(int k=0; k<MAX; k++) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if(possible[i][j] && check[i][j]) go(i,j);
			}
		}
	}

	// count 
	int ans=0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if(check[i][j]) ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
