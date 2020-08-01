#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int N,M;
string s[20];
int d[20][20];
bool check[20][20];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int ans=-1;

int bfs(vector<pi> &p) {
	memset(d,-1,sizeof(d));
	
	queue<pi> q;
	for(auto &each : p) {
		int x=each.first;
		int y=each.second;
		
		d[x][y]=0;
		q.push(make_pair(x,y));
	}
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	
	int move=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(s[i][j]=='1') move=max(move,d[i][j]);	
		}
	}
	
	return move;
}

void go(int x, int y, vector<pi> &p) {
	if(p.size()==2) {
		int move=bfs(p);
		if(ans==-1 || ans>move) ans=move;
		return;
	}
	
	for(int i=x; i<N; i++) {
		for(int j=y; j<M; j++) {
			if(s[i][j]=='1' || check[i][j]==true) continue;
			check[i][j]=true;
			p.push_back(make_pair(i,j));
			go(i,j,p);
			check[i][j]=false;
			p.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M;
	for(int i=0; i<N; i++) cin>>s[i];
	
	vector<pi> a;
	go(0,0,a);
	cout<<ans;
	
	return 0;
}
