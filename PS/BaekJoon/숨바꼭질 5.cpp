#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dist[500001][2];

int main() {
	int n, k;
	cin>>n>>k;
	
	memset(dist,-1,sizeof(dist));

	queue<pair<int,int>> q;
	q.push(make_pair(n, 0));
	dist[n][0]=0;
	
	while(!q.empty()) {
		int x, t;
		tie(x, t)=q.front();
		q.pop();
		
		for(int y : {x+1, x-1, 2*x}) {
			if(0<=y && y<=500000) {
				if(dist[y][1-t]==-1) {
					dist[y][1-t]=dist[x][t]+1;
					q.push(make_pair(y, 1-t));
				}
			}
		}
	}
	
	int ans=-1;
	for(int t=0;;t++) {
		k+=t;
		if(k>500000) break;
		
		if(dist[k][t%2]<=t) {
			ans=t;
			break;
		}
	}
	cout<<ans;
	
	return 0;
}
