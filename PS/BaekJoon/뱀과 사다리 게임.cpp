#include <iostream>
#include <queue>

using namespace std;

int check[101];
int dist[101];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=100; i++) {
		check[i]=i;
		dist[i]=-1;
	}
	
	for(int i=0; i<n+m; i++) {
		int x,y;
		cin>>x>>y;
		
		check[x]=y;
	}

	queue<int> q;
	q.push(1);
	dist[1]=0;
	
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		
		for(int i=1; i<=6; i++) {
			int next=now+i;
			if(next>100) break;
			
			next=check[next];
			if(dist[next]==-1) {
				dist[next]=dist[now]+1;
				q.push(next);
			}
		}
	}

	cout<<dist[100];	

	return 0;
}

/*
INPUT:
3 7
32 62
42 68
12 98
95 13
97 25
93 37
79 27
75 19
49 47
67 17

OUTPUT:
3
*/
