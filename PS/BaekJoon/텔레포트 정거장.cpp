#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int d[300001];
vector<int> t[300001];

int main() {
	memset(d,-1,sizeof(d));

	int N,M,S,E;
	cin>>N>>M>>S>>E;
	
	for(int i=0; i<M; i++) {
		int x,y;
		cin>>x>>y;
		
		t[x].push_back(y);
		t[y].push_back(x);
	}

	queue<int> q;
	q.push(S);
	d[S]=0;
	
	while(!q.empty()) {
		int current=q.front();
		q.pop();
		
		int forward=current+1;
		if(forward<=N) {
			if(d[forward]==-1 || d[forward]>d[current]+1) {
				d[forward]=d[current]+1;
				q.push(forward);
			}
		}
		
		int backward=current-1;
		if(backward>=0) {
			if(d[backward]==-1 || d[backward]>d[current]+1) {
				d[backward]=d[current]+1;
				q.push(backward);
			}
		}
		
		for(auto x : t[current]) {
			if(d[x]==-1 || d[x]>d[current]+1) {
				d[x]=d[current]+1;
				q.push(x);
			}
		}
	}
	
	cout<<d[E];
	
	return 0;
}
