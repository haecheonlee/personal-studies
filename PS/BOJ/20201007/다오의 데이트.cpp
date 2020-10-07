#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

const int MAX=2e1+1;

int N,M;
char a[MAX][MAX];
bool check[MAX][MAX][MAX];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int convert(char move) {
	if(move=='W') return 0;
	else if(move=='D') return 1;
	else if(move=='S') return 2;
	else return 3;
}

bool is_in_range(int x, int y) {
	return 0<=x && x<N && 0<=y && y<M;
}

int main() {
	cin>>N>>M;
	
	int sx, sy, ex, ey;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='D') sx=i, sy=j;	
			else if(a[i][j]=='Z') ex=i, ey=j;
		}
	}

	int K;
	cin>>K;
	
	vector<vector<char>> p;
	for(int i=0; i<K; i++) {
		char m1, m2;
		cin>>m1>>m2;
		
		p.push_back({m1,m2});
	}

	queue<pair<pi,pair<int,string>>> q;
	q.push({ {sx,sy} , {0,""} });
	check[sx][sy][0]=true;
	
	while(!q.empty()) {
		int x=q.front().first.first;
		int y=q.front().first.second;
		int idx=q.front().second.first;
		string move=q.front().second.second;
		q.pop();
		
		if(x==ex && y==ey) {
			cout<<"YES\n"<<move;
			return 0;
		}
		if(idx==K) continue;
		
		for(auto& m : p[idx]) {
			int k=convert(m);
			int nx=x+dx[k], ny=y+dy[k];

			if(is_in_range(nx, ny)) {
				if(a[nx][ny]!='@') {
					if(check[nx][ny][idx+1]==false) {
						check[nx][ny][idx+1]=true;
						q.push({{nx,ny},{idx+1, move+m}});
					}
				}
			}
		}
	}
	
	cout<<"NO";

	return 0;
}
