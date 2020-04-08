#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

typedef pair<int,int> pi;
typedef tuple<int,int,int> tpl;

int n,m,g,r;
int a[50][50];
int ans=0;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
vector<pi> list;
vector<int> vec;
vector<int> green, red;
bool check[10];

void bfs() {
	int d[50][50][2];
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			d[i][j][0]=0;
			d[i][j][1]=0;
		}
	}
	
	
	deque<tpl> dq;

	for(int i=0; i<green.size(); i++) {
		int pos=vec[green[i]];
		
		int x=list[pos].first;
		int y=list[pos].second;
		
		d[x][y][0]=1;
		d[x][y][1]=0;
		dq.push_front(make_tuple(x,y,0));
	}
	
	for(int i=0; i<red.size(); i++) {
		int pos=vec[red[i]];
		
		int x=list[pos].first;
		int y=list[pos].second;
		
		d[x][y][0]=2;
		d[x][y][1]=0;
		dq.push_front(make_tuple(x,y,0));
	}

	while(!dq.empty()) {
		int x,y,t;
		tie(x,y,t)=dq.front();
		dq.pop_front();
		if(d[x][y][0]==3) continue;
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(a[nx][ny]==0) continue;
				if(d[nx][ny][0]==3) continue;
				
				int next_time=d[x][y][1]+1;
				if(d[nx][ny][0]==0) {
					d[nx][ny][0]=d[x][y][0];
					d[nx][ny][1]=next_time;
					
					dq.push_back(make_tuple(nx,ny,next_time));
				} else {
					if(d[x][y][0]!=d[nx][ny][0]) {
						if(d[nx][ny][1]==next_time) {
							d[nx][ny][0]=3;
						}
					}
				}
			}
		}
	}
	
	int cnt=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(d[i][j][0]==3) cnt++;
		}
	}

	ans=max(ans,cnt);
}

void set(int index) {
	if(index==vec.size()) {
		if(green.size()!=g) return;
		
		red=vector<int>();
		for(int i=0; i<g+r; i++) {
			if(!check[i]) red.push_back(i);
		}

		bfs();
		
		return;
	}
	
	green.push_back(index);
	check[index]=true;
	set(index+1);
	
	green.pop_back();
	check[index]=false;
	set(index+1);
}

void go(int index) {
	if(index==list.size()) {
		if(vec.size()!=(g+r)) return;
		set(0);
		return;
	}
	
	vec.push_back(index);
	go(index+1);
	vec.pop_back();
	go(index+1);
}

int main() {
	cin>>n>>m>>g>>r;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) { 
			cin>>a[i][j];
			if(a[i][j]==2) list.push_back(make_pair(i,j));
		}
	}
	
	go(0);
	cout<<ans;
	
	return 0;
}

/*
INPUT:
13 20 2 5
1 1 0 1 0 0 1 0 0 2 0 1 0 0 1 2 0 2 1 1
1 1 0 1 1 0 0 0 0 0 0 1 0 1 0 0 0 0 1 1
0 0 0 1 1 0 1 0 0 0 0 1 0 0 1 0 1 0 1 0
0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 1 1 1 1 0
1 2 0 0 0 1 0 0 1 1 0 1 1 0 0 1 1 0 1 0
0 1 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 0 1
1 0 1 1 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 0
0 1 1 1 0 0 1 1 0 0 0 0 0 0 0 1 0 1 0 0
0 1 0 0 1 1 0 1 0 0 0 0 1 0 1 0 0 1 0 0
0 0 2 0 0 0 0 0 2 1 0 1 0 0 0 0 0 0 0 0
1 1 0 0 0 1 0 2 1 0 0 0 1 1 0 0 0 0 0 0
0 0 0 0 1 1 0 0 1 0 0 0 1 1 2 1 0 1 0 1
0 0 0 1 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0

OUTPUT:
1
*/
