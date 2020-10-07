#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX=51;

int N;
vector<int> a[MAX];
bool check[MAX];
int d[MAX], score[MAX];

void bfs(int sx) {
	memset(d, -1, sizeof(d));
	
	queue<int> q;
	q.push(sx);
	d[sx]=0;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& y : a[x]) {
			if(d[y]==-1) {
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	
	int x=-1;
	for(int i=1; i<=N; i++) x=max(x, d[i]);
	score[sx]=x;
}

int main() {
	cin>>N;
	
	while(1) {
		int u,v;
		cin>>u>>v;
		
		if(u==-1 && v==-1) break;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for(int i=1; i<=N; i++) bfs(i);

	pair<int,vector<int>> ans;
	ans.first=MAX;
	for(int i=1; i<=N; i++) {
		if(ans.first==score[i]) {
			ans.second.push_back(i);
		} else if(ans.first>score[i]) {
			ans.first=score[i];
			ans.second.clear();
			ans.second.push_back(i);
		}
	}

	cout<<ans.first<<' '<<ans.second.size()<<'\n';
	for(auto& x : ans.second) cout<<x<<' ';

	return 0;
}
