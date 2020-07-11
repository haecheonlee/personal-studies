#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> a[100000];
int order[100000];
bool check[100000];

bool cmp(const int &x, const int &y) {
	return order[x]<order[y];
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N-1; i++) {
		int x,y;
		cin>>x>>y;
		
		x-=1;
		y-=1;
		
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	vector<int> b(N);
	for(int i=0; i<N; i++) {
		cin>>b[i];
		
		b[i]-=1;
		order[b[i]]=i;
	}
	
	for(int i=0; i<N; i++) {
		sort(a[i].begin(), a[i].end(), cmp);
	}
	
	vector<int> bfs_order;
	
	queue<int> q;
	q.push(0);
	check[0]=true;
	
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		bfs_order.push_back(x);
		for(int y : a[x]) {
			if(check[y]==false) {
				check[y]=true;
				q.push(y);
			}
		}
	}
	
	if(bfs_order==b) cout<<1;
	else cout<<0;
	
	return 0;
}
