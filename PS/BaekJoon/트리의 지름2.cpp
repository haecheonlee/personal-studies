#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

vector<pi> a[10001];
int d[10001];		// length from node 1
bool check[10001];

void go(int start) {
	memset(d,0,sizeof(d));
	memset(check,false,sizeof(check));
	
	queue<int> q;
	q.push(start);
	d[start]=0;
	check[start]=true;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(const auto& p : a[x]) {
			int y=p.first;
			int cost=p.second;
			
			if(check[y]==false) {
				d[y]=d[x]+cost;
				check[y]=true;
				q.push(y);
			}
		}
	}
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N-1; i++) {
		int from,to,cost;
		cin>>from>>to>>cost;
		
		a[from].push_back(make_pair(to,cost));
		a[to].push_back(make_pair(from,cost));
	}
	
	// run bfs from node 1
	go(1);

	// find the most further nodes
	int node=1;
	for(int i=1; i<=N; i++) {
		if(d[i]>d[node]) node=i;
	}
	go(node);
	
	int ans=d[1];
	for(int i=1; i<=N; i++) {
		if(d[i]>ans) ans=d[i];
	}
	cout<<ans;
	
	return 0;
}
