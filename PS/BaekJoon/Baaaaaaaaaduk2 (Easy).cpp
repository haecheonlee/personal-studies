#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int n,m,ans=0;
int a[25][25];
bool check[25][25];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
vector<pair<int,int>> list;

int bfs() {
	memset(check,false,sizeof(check));

	int total=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j]==2 && check[i][j]==false) {
				bool dead=true;
				int cnt=0;
				
				queue<pair<int,int>> q;
				q.push(make_pair(i,j));
				check[i][j]=true;
				
				while(!q.empty()) {
					int x,y;
					tie(x,y)=q.front();
					q.pop();
					
					cnt+=1;
					for(int k=0; k<4; k++) {
						int nx=x+dx[k];
						int ny=y+dy[k];
						
						if(0<=nx && nx<n && 0<=ny && ny<m) {
							if(a[nx][ny]==0) dead=false;
							else if(a[nx][ny]==2 && check[nx][ny]==false) {
								q.push(make_pair(nx,ny));
								check[nx][ny]=true;
							}
						}
					}
				}
				
				if(dead) total+=cnt;
			}
		}
	}
	
	return total;
}

void go(vector<int> vec, int index) {
	if(vec.size()==2) {
		
		// set
		for(int i=0; i<2; i++) a[list[vec[i]].first][list[vec[i]].second]=1;
	
		int cnt=bfs();
		ans=max(ans,cnt);
		
		// reset
		for(int i=0; i<2; i++) a[list[vec[i]].first][list[vec[i]].second]=0;
		
		return;
	}
	
	if(index>=list.size()) return;
	vec.push_back(index);
	go(vec,index+1);
	vec.pop_back();
	go(vec,index+1);
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) { 
			cin>>a[i][j];
			if(a[i][j]==0) list.push_back(make_pair(i,j));
		}
	}
	
	go(vector<int>(),0);
	cout<<ans;
	
	return 0;
}

/*
INPUT:
8 6
0 0 1 2 2 2
0 0 1 2 2 2
0 1 1 0 2 2
1 2 2 0 1 1
1 2 2 1 0 0
1 2 1 0 2 0
1 1 0 0 0 1
0 1 0 0 0 0

OUTPUT:
13
*/
