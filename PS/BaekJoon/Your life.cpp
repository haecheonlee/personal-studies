#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX=1e5+1;

vector<int> a[MAX];
int d[MAX];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
	}

	memset(d,-1,sizeof(d));	
	queue<int> q;
	q.push(1);
	d[1]=0;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& y : a[x]) {
			if(d[y]==-1 || d[y]>d[x]+1) {
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	cout<<d[N];
	
	return 0;
}
