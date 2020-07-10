#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[3000];
int check[3000];	// 0: not visited, 1: visited, 2: cycle
int dist[3000];

int go(int x, int p) {
	// -2 : found cycle and not included
	// -1 : cycle not found
	// 0~n-1: cycle found and start index
	
	if(check[x]==1) return x;
	check[x]=1;
	for(int y : a[x]) {
		if(y==p) continue;
		
		int res=go(y,x);
		if(res==-2) return -2;
		if(res>=0) {
			check[x]=2;
			if(x==res) return -2;
			else return res;
		}
	}
	
	return -1;
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		int x,y;
		cin>>x>>y;
		
		x-=1;
		y-=1;
		
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	// dfs to find cycle
	go(0,-1);
	
	queue<int> q;
	for(int i=0; i<N; i++) {
		if(check[i]==2) {
			dist[i]=0;
			q.push(i);
		} else {
			dist[i]=-1;
		}
	}
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto y : a[x]) {
			if(dist[y]==-1) {
				q.push(y);
				dist[y]=dist[x]+1;
			}
		}
	}
	
	for(int i=0; i<N; i++) {
		cout<<dist[i]<<" ";	
	}
	
	return 0;
}
