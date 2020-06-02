#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[1001];
int in_degree[1001];
int semester[1001];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) {
		in_degree[i]=0;
		semester[i]=1;	
	}
	
	for(int i=0; i<m; i++) {
		int x,y;
		cin>>x>>y;
		
		a[x].push_back(y);
		in_degree[y]++;
	}
	
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(in_degree[i]==0) q.push(i);
	}
	
	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		for(auto next : a[current]) {
			in_degree[next]--;
			
			if(in_degree[next]==0) {
				semester[next]=max(semester[next], semester[current]+1);
				q.push(next);
			}
		}
	}
	
	for(int i=1; i<=n; i++) cout<<semester[i]<<" ";
	
	return 0;
}
