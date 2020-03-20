#include <iostream>
#include <queue>

using namespace std;

int f,s,g,u,d;
int dist[1000001];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	dist[start]=0;
	
	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		int up=current+u;
		if(up<=f) {
			if(dist[up]==-1) {
				dist[up]=dist[current]+1;
				q.push(up);
			}
		}
		
		int down=current-d;
		if(down>0) {
			if(dist[down]==-1) {
				dist[down]=dist[current]+1;
				q.push(down);
			}
		}
	}
}

int main() {
	cin>>f>>s>>g>>u>>d;
	
	fill(dist, dist+f+1, -1);
	bfs(s);
	
	if(dist[g]==-1) cout<<"use the stairs";
	else cout<<dist[g];
	
	return 0;
}

/*
INPUT:
10 1 10 2 1

OUTPUT:
6
*/
