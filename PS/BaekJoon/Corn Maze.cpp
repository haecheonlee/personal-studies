/* reference: usaco analysis */

#include <iostream>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;
using pi=pair<int,int>;

const int MAX=3e2+1;

char a[MAX][MAX];
pi tp[26][2];
bool check[MAX][MAX];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main() {
	memset(tp, -1, sizeof(tp));
	
	int N,M;
	cin>>N>>M;
	
	int sx=-1, sy=-1, ex=-1, ey=-1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='@') {
				sx=i;
				sy=j;
			} else if(a[i][j]>='A' && a[i][j]<='Z') {
				int idx=a[i][j]-'A';

			 	if(tp[idx][0].first==-1 && tp[idx][0].second==-1) tp[idx][0]=make_pair(i,j);
				else tp[idx][1]=make_pair(i,j);
			}
		}
	}
	
	queue<pair<pi,int>> q;
	q.push({{sx,sy}, 0});
	while(!q.empty()) {
		int x=q.front().first.first;
		int y=q.front().first.second;
		int cost=q.front().second;
		q.pop();
		
		if(a[x][y]=='=') {
			cout<<cost;
			break;
		}
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]=='.' || a[nx][ny]=='=') {
					if(check[nx][ny]==false) {
						check[nx][ny]=true;
						q.push({{nx,ny}, cost+1});
					}
				} else if(a[nx][ny]>='A' && a[nx][ny]<='Z') {
					int idx=a[nx][ny]-'A';
					pi current_tp;
					if(tp[idx][0]==make_pair(nx,ny)) current_tp=tp[idx][1];
					else current_tp=tp[idx][0];
					
					if(check[current_tp.first][current_tp.second]==false) {
						check[current_tp.first][current_tp.second]=true;
						q.push({current_tp, cost+1});
					}
				}
			}
		}
	}

	return 0;
}
