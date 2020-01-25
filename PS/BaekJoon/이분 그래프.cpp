#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[20001];
int color[20001];

bool dfs(int node, int c) {
	color[node]=c;
	for(int i=0; i<vec[node].size(); i++) {
		int next=vec[node][i];
		if(color[next]==0) {
			if(dfs(next,3-c)==false) {
				return false;
			}
		} else if(color[next]==color[node]) {
			return false;
		}
	}
	
	return true;
}

int main() {
	int k,v,e;
	cin>>k;

	while(k--) {
		cin>>v>>e;
		
		for(int i=1; i<=v; i++) {
			vec[i].clear();
			color[i]=0;
		}
		
		int a,b;
		for(int i=0; i<e; i++) {
			cin>>a>>b;
			
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		
		bool check=true;
		for(int i=1; i<=v; i++) {
			if(color[i]==0) {
				if(dfs(i,1)==false) {
					check=false;
				}
			}
		}
		
		cout<<((check) ? "YES" : "NO")<<'\n';
	}
	
	return 0;
}

/*
boj.kr/1707

INPUT:
2
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2

OUTPUT:
YES
NO
*/
