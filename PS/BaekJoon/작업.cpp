#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> list[10001];
int in_degree[10001] {0};
int work[10001] {0};
int measure[10001] {0};

int main() {
	int n;
	cin>>n;
	
	int t,k,w;
	for(int i=1; i<=n; i++) {
		cin>>t>>k;
		
		measure[i]=t;
		work[i]=t;
		while(k--) {
			cin>>w;
			
			list[w].push_back(i);
			in_degree[i]+=1;
		}
	}
	
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(in_degree[i]==0) q.push(i);
	}
	
	int mx=-1;
	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		mx=max(mx,measure[current]);
		for(int i=0; i<list[current].size(); i++) {
			int next=list[current][i];
			
			measure[next]=max(measure[current]+work[next], measure[next]);
			
			in_degree[next]-=1;
			if(in_degree[next]==0) q.push(next);
		}
	}
	

	cout<<mx;

	return 0;
}

/*
INPUT:
7
5 0
1 1 1
3 1 2
6 1 1
1 2 2 4
8 2 2 4
4 3 3 5 6

OUTPUT:
23
*/
