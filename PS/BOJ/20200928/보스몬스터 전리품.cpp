#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3;
const int HEALTH=1e6+1;

int N,M,P;
char a[MAX][MAX];
int d[MAX][MAX];
pair<pi,int> p[26];
pi t[HEALTH];
vector<int> player;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy) {
	memset(d, -1, sizeof(d));
	queue<pi> q;
	q.push({sx,sy});
	d[sx][sy]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]=='X') continue;
				if(d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push({nx,ny});
				}
			}
		}
	}
}

int main() {
	cin>>N>>M>>P;
	
	int bx, by;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='B') {
				// position of boss
				bx=i;
				by=j;
			} else if(a[i][j]>='a' && a[i][j]<='z') {
				// position of player
				player.push_back(a[i][j]-'a');
				p[a[i][j]-'a'].first.first=i;
				p[a[i][j]-'a'].first.second=j;
			}
		}
	}
	
	for(int i=0; i<P; i++) {
		char id;
		int dps;
		
		cin>>id>>dps;
		p[id-'a'].second=dps;
	}
	
	int HP;
	cin>>HP;

	bfs(bx,by);
	
	for(int i=0; i<player.size(); i++) {
		int x=p[player[i]].first.first;
		int y=p[player[i]].first.second;
		int power=p[player[i]].second;
		if(d[x][y]==-1) continue;

		t[d[x][y]-1].first+=power;
		t[d[x][y]-1].second++;
	}

	int damaged=0, ans=0, current_time=0;
	vector<int> acc;
	while(1) {
		acc.push_back(t[current_time].first);
		for(auto& dps : acc) damaged+=dps;
		ans+=t[current_time].second;
		current_time++;
		if(damaged>=HP) break;
	}
	cout<<ans;
	
	return 0;
}
