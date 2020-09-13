#include <iostream>
#include <vector>

using namespace std;

const int MAX=2e5+1;

vector<int> a[MAX];
bool check[MAX];
bool check2[MAX];

int go(int x) {
	int total=(check2[x]==false);
	
	check[x]=check2[x]=true;
	for(auto& y : a[x]) {
		if(check2[y]==false) {
			check2[y]=true;
			total++;
		}
	}
	
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M,Q;
	cin>>N>>M>>Q;
	
	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}

	while(Q--) {
		int x;
		cin>>x;
		
        if(check[x]) cout<<0<<'\n';
        else cout<<go(x)<<'\n';
	}

	return 0;
}
