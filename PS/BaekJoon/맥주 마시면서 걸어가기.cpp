#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using pi=pair<int,int>;
const int MAX=101;

vector<int> v[MAX];
bool check[MAX];

void dfs(int node) {
	check[node]=true;
	for(const auto& next : v[node]) {
		if(check[next]==false) dfs(next);
	}
}

bool calc(const pi &a, const pi &b) {
	int dist=abs(a.first-b.first)+abs(a.second-b.second);
	return dist<=1000;
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		N+=2;
		
		// reset
		for(int i=0; i<N; i++) {
			v[i].clear();
			check[i]=false;
		}
		
		vector<pi> p(N);
		for(int i=0; i<N; i++) cin>>p[i].first>>p[i].second;
		
		for(int i=0; i<N; i++) {
			for(int j=i+1; j<N; j++) {
				bool is_possible=calc(p[i],p[j]);
				
				if(is_possible) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		
		dfs(0);
		
		// select the node of destination
		if(check[N-1]) cout<<"happy\n";
		else cout<<"sad\n";
	}

	return 0;
}
