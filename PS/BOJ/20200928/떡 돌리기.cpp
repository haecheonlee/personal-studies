#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3;

vector<pi> a[MAX];
int d[MAX];

void bfs(int sx) {
	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(sx);
	d[sx]=0;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& next : a[x]) {
			int y=next.second;
			int dist=next.first;
			
			if(d[y]==-1 || d[y]>d[x]+dist) {
				d[y]=d[x]+dist;
				q.push(y);
			}
		}
	}
}

int main() {
	int N,M,X,Y;
	cin>>N>>M>>X>>Y;
	
	for(int i=0; i<M; i++) {
		int u,v,k;
		cin>>u>>v>>k;
		
		a[u].push_back({k,v});
		a[v].push_back({k,u});
	}
	
	bfs(Y);
	vector<int> p;
	for(int i=0; i<N; i++) {
		if(i==Y) continue;
		p.push_back(d[i]);
	}
	sort(p.begin(), p.end());
	
	bool is_possible=true;
	int ans=0, sum=0;
	for(int i=0; i<p.size(); i++) {
		if(p[i]*2>X) {
			is_possible=false;
			break;
		} else {
			if(sum+(p[i]*2)>X) {
				i--, sum=0;
				ans++;
			} else {
				sum+=(p[i]*2);
			}
		}
	}
	
	if(is_possible) cout<<ans+(sum!=0);
	else cout<<-1;
	
	return 0;
}
