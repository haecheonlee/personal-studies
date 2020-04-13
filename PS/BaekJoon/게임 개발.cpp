#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> list[501];
int in_degree[501] {0};
int t[501];
int measure[501];

int main() {
	int n;
	cin>>n;
	
	for(int i=1; i<=n; i++) {
		cin>>t[i];
		
		measure[i]=t[i];
		while(1) {
			int x;
			cin>>x;
			
			if(x==-1) break;
			list[x].push_back(i);
			in_degree[i]+=1;
		}
	}
	
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(in_degree[i]==0) q.push(i);
	}

	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		for(int i=0; i<list[current].size(); i++) {
			int next=list[current][i];

			in_degree[next]-=1;
			measure[next]=max(measure[next], measure[current]+t[next]);

			if(in_degree[next]==0) q.push(next);
		}
	}
	
	for(int i=1; i<=n; i++) cout<<measure[i]<<'\n';

	return 0;
}

/*
INPUT:
5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1

OUTPUT:
10
20
14
18
17
*/
