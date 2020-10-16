/* reference: https://github.com/kks227/BOJ/blob/master/12700/12763.cpp */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX=1e2+1;
const int IMPOSSIBLE=1e9;

struct Edge {
	int y, t, c;
	Edge(int _y, int _t, int _c) : y(_y), t(_t), c(_c) {}
};

int N,T,C,M;
vector<Edge> a[MAX];
int d[MAX][10001];

int go(int x, int t) {
	if(x==N) return 0;

	int& ret=d[x][t];
	if(ret!=-1) return ret;
	ret=IMPOSSIBLE;
	
	for(auto &e : a[x]) {
		int y=e.y;
		if(t>=e.t) ret=min(ret, go(y, t-e.t) + e.c);
	}
	
	return ret;
}

int main() {
	cin>>N>>T>>C>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,t,c;
		cin>>u>>v>>t>>c;
		
		a[u].push_back({v,t,c});
		a[v].push_back({u,t,c});
	}

	memset(d, -1, sizeof(d));
	int ans=go(1,T);
	cout<<((ans<=C) ? ans : -1);
	
	return 0;
}
