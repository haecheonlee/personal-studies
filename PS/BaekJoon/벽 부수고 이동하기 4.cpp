#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n,m;
int count[501];
int a[1001][1001];
int group[1001][1001];
vector<int> group_size;
bool check[1001][1001];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int i, int j) {
	int g=group_size.size();
	int cnt=1;
	
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	check[i][j]=true;
	group[i][j]=g;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(check[nx][ny]==false && a[nx][ny]==0) {
					check[nx][ny]=true;
					group[nx][ny]=g;
					q.push(make_pair(nx,ny));
					
					cnt++;
				}
			}
		}
	}
	
	group_size.push_back(cnt);
}

void solve(int x, int y) {
	set<int> groups;
	for(int k=0; k<4; k++) {
		int nx=dx[k]+x;
		int ny=dy[k]+y;
		
		if(0<=nx && nx<n && 0<=ny && ny<m) {
			if(a[nx][ny]==0) groups.insert(group[nx][ny]);
		}
	}
	
	int ans=1;
	for(auto g : groups) ans+=group_size[g];
	ans%=10;
	
	a[x][y]=ans;
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		string s;
		cin>>s;
		
		for(int j=0; j<m; j++) {
			a[i][j]=s[j]-'0';
			check[i][j]=false;
			group[i][j]=-1;
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j]==0 && check[i][j]==false) bfs(i,j);	
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j]==1) solve(i,j);
			cout<<a[i][j];
		}
		cout<<'\n';
	}
	
	return 0;
}

/*
INPUT:
4 5
11001
00111
01010
10101

OUTPUT:
46003
00732
06040
50403
*/
