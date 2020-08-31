#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX=2e5+1;

vector<int> a[MAX];
int d[MAX];
bool check[MAX];

int main() {
	int C,P,X,L;
	cin>>C>>P>>X>>L;
	
	for(int i=0; i<P; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
		
		d[u]++;
		d[v]++;
	}
	
	for(int i=1; i<=C; i++) d[i]=(d[i]+1)/2;

	queue<int> q;
	q.push(L);
	check[L]=true;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		
		for(auto& y : a[x]) {
			d[y]--;
			if(d[y]<=0) {
				if(check[y]==false) {
					check[y]=true;
					q.push(y);
				}
			}
		}
	}

	if(check[X]) cout<<"leave";
	else cout<<"stay";

	return 0;
}
