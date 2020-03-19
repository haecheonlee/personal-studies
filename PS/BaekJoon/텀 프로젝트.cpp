#include <iostream>

using namespace std;

int d[100001];
int n,cnt;
bool visited[100001], finished[100001];

void dfs(int current) {
	visited[current]=true;
	int next=d[current];
	
	if(visited[next]) {
		if(!finished[next]) {
			cnt++;
			for(int temp=next; temp!=current; temp=d[temp]) cnt+=1;
		}
	} else {
		dfs(next);
	}
	
	finished[current]=true;
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n;
		cin>>n;
		
		for(int i=0; i<n; i++) {
			cin>>d[i];
			d[i]-=1;
		}
		
		fill(visited, visited+n, false);
		fill(finished, finished+n, false);
		cnt=0;
		
		for(int i=0; i<n; i++) {
			if(!visited[i]) dfs(i);
		}
		
		cout<<n-cnt<<'\n';
	}
	
	return 0;
}

/*
INPUT:
2
7
3 1 3 7 3 4 6
8
1 2 3 4 5 6 7 8

OUTPUT:
3
0
*/
