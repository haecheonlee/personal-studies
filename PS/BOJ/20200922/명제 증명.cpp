#include <iostream>
#include <vector>

using namespace std;
using pi=pair<int,int>;

const int MAX=60;

int adj[MAX][MAX];

int get_index(char x) {
	if(x>='A' && x<='Z') return (x-'A');
	else return (x-'a')+26;
}

char convert(int idx) {
	if(idx>=0 && idx<=25) return 'A'+idx;
	else return 'a'+(idx-26);
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		char u,v;
		string x;
		cin>>u>>x>>v;
		
		int ui=get_index(u);
		int vi=get_index(v);
		
		adj[ui][vi]=true;
	}
	
	for(int k=0; k<MAX; k++) {
		for(int i=0; i<MAX; i++) {
			for(int j=0; j<MAX; j++) {
				if(adj[i][j]==false) {
					adj[i][j]=(adj[i][k] && adj[k][j]);
				}
			}
		}
	}

	vector<pi> ans;
	for(int x=0; x<MAX; x++) {
		for(int y=0; y<MAX; y++) {
			if(adj[x][y]==false || x==y) continue;
			ans.push_back({x,y});
		}
	}

	cout<<ans.size()<<'\n';
	for(auto& p : ans) cout<<convert(p.first)<<" => "<<convert(p.second)<<'\n';

	return 0;
}
