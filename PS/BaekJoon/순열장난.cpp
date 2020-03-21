#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[51];
vector<int> ans;

void dfs(string s, vector<int> perm) {
	if(s=="") {
		int mx=*max_element(perm.begin(), perm.end());
		bool check=true;
		for(int i=1; i<=mx; i++) {
			if(visited[i]==false) {
				check=false;
				break;
			}
		}
		
		if(check) ans=perm;
		return;
	}
	// single
	int sgl=stoi(s.substr(0,1));
	if(visited[sgl]==false) {
		visited[sgl]=true;
		perm.push_back(sgl);
		dfs(s.substr(1), perm);
		visited[sgl]=false;
		perm.pop_back();
	}
	// double
	int dbl=stoi(s.substr(0,2));
	if(visited[dbl]==false) {
		if(s.length()>=2) {
			visited[dbl]=true;
			perm.push_back(dbl);
			dfs(s.substr(2),perm);
			visited[dbl]=false;
		}
	}
}

int main() {
	string s;
	cin>>s;
	
	dfs(s,vector<int>());
	
	for(auto &i : ans) {
		cout<<i<<" ";
	}
	
	return 0;
}

/*
INPUT:
4111109876532

OUTPUT:
4 1 11 10 9 8 7 6 5 3 2
*/
