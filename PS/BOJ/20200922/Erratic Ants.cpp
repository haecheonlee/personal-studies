#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e2+2e1+1;

const int E=0, W=1, S=2, N=3;

int a[MAX][MAX];
int d[MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		memset(a, -1, sizeof(a));
		memset(d, -1, sizeof(d));
		set<int> p[MAX];
		
		int M;
		cin>>M;
		
		int sx=60, sy=60, ex=60, ey=60;
		int node=0;
		a[sx][sy]=node;
		
		for(int i=0; i<M; i++) {
			char move;
			cin>>move;
			
			int cx=ex, cy=ey;
			if(move=='E') ex+=dx[E], ey+=dy[E];
			else if(move=='W') ex+=dx[W], ey+=dy[W];
			else if(move=='S') ex+=dx[S], ey+=dy[S];
			else if(move=='N') ex+=dx[N], ey+=dy[N];
			
			if(a[ex][ey]==-1) {
				a[ex][ey]=node+1;
				p[a[cx][cy]].insert(node+1);
				p[node+1].insert(a[cx][cy]);
				node++;
			} else {
				p[a[cx][cy]].insert(a[ex][ey]);
				p[a[ex][ey]].insert(a[cx][cy]);
			}
		}
		
		queue<int> q;
		q.push(a[sx][sy]);
		d[a[sx][sy]]=0;

		while(!q.empty()) {
			int x=q.front();
			q.pop();
			
			for(auto& y : p[x]) {
				if(d[y]==-1) {
					d[y]=d[x]+1;
					q.push(y);
				}
			}
		}
		
		cout<<d[a[ex][ey]]<<'\n';
	}
	
	return 0;
}
