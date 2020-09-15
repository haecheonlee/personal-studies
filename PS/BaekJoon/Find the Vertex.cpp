/* reference: editorial */

#include <iostream>
#include <vector>

using namespace std;

const int MAX=5e5+1;

int p[MAX];
vector<int> a[MAX];
vector<int> list;

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) {
		cin>>p[i];
		if(p[i]==0)	list.push_back(i);
	}
	
	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	for(auto& x : list) {
		bool is_possible=true;
		
		for(auto& y : a[x]) {
			if(p[y]!=1) {
				is_possible=false;
				break;
			}
		}
		
		if(is_possible) {
			cout<<x;
			break;
		}
	}
	
	return 0;
}
