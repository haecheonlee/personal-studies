#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX=1e3;

int N;
vector<int> p[1000];
vector<int> a[1000][10];
vector<int> ans;
int check[1000][10][10];

bool dfs(int index, int x) {
	if(ans.size()==N) return true;
	
	for(auto& y : a[index][x]) {
		int& ret=check[index][x][y];
		if(ret!=-1) return ret;
		
		ans.push_back(y);
		ret=dfs(index+1,y);
		if(ret) return true;
		ans.pop_back();
	}
	
	return false;
}

int main() {
	cin>>N;
	
	memset(check,-1,sizeof(check));
	for(int i=0; i<N; i++) {
		int M;
		cin>>M;
		
		while(M--) {
			int x;
			cin>>x;
			
			p[i].push_back(x);
		}
	}

	for(int i=0; i<N-1; i++) {
		for(int x=0; x<p[i].size(); x++) {
			for(int y=0; y<p[i+1].size(); y++) {
				if(p[i][x]==p[i+1][y]) continue;
				a[i][p[i][x]].push_back(p[i+1][y]);
			}
		}
	}

	for(auto& start : p[0]) {
		ans.clear();
		ans.push_back(start);
		dfs(0,start);
		
		if(ans.size()==N) {
			for(auto& x : ans) cout<<x<<'\n';
			return 0;
		}
	}
	
	cout<<-1;

	return 0;
}
