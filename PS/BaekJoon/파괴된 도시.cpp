#include <iostream>
#include <vector>

using namespace std;

int N,M,K;
vector<int> a[2001];
bool check[2001];
bool ans[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M;

	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}

	cin>>K;
	for(int i=0; i<K; i++) {
		int x;
		cin>>x;
		
		check[x]=true;
	}
	
	vector<int> city;
	for(int x=1; x<=N; x++) {
		if(check[x]==false) continue;
		bool is_possible=true;
		for(auto& y : a[x]) {
			if(check[y]==false) {
				is_possible=false;
				break;
			}
		}
		
		if(is_possible) city.push_back(x);
	}

	for(auto& x : city) {
		ans[x]=true;
		for(auto& y : a[x]) ans[y]=true;
	}

	bool is_possible=true;
	for(int i=1; i<=N; i++) {
		if(check[i]!=ans[i]) {
			is_possible=false;
			break;
		}
 	}
 	
 	if(is_possible) {
 		cout<<city.size()<<'\n';
 		for(auto& x : city) cout<<x<<" ";
 	}else {
 		cout<<-1;
 	}
 	
	return 0;
}
