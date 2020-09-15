#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX=1e5;
	
vector<int> a[MAX];
int d[MAX];

int main() {
	int N,M;
	cin>>N>>M;

	for(int i=0; i<M; i++) {
		int x, y1, y2;
		cin>>x>>y1>>y2;
		
		a[x].push_back(y1);
		a[x].push_back(y2);
	}

	queue<int> q;
	q.push(1);
	d[1]=1;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& y : a[x]) {
			if(d[y]==0) {
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	
	for(int i=1; i<=N; i++) 
		cout<<d[i]<<'\n';

	return 0;
}
