#include <iostream>
#include <vector>

using namespace std;

const int MAX=1e2;

vector<int> a[MAX];
vector<int> ans[MAX];
bool check[MAX];
int idx=0;

void dfs(int x) {
	check[x]=true;
	ans[idx].push_back(x);

	for(auto& y : a[x]) {
		if(check[y]==false) dfs(y);
	}
}

int main() {
	int N;
	cin>>N;

	for(int i=0; i<N; i++) {
		bool is_not_possible=true;
		
		for(int j=0; j<N; j++) {
			int x;
			cin>>x;
			
			if(x==0) {
				if(i!=j) is_not_possible=false;
				
				a[i].push_back(j);
				a[j].push_back(i);
			}
		}
		
		if(is_not_possible) {
			cout<<0;
			return 0;
		}
	}
	
	for(int i=0; i<N; i++) {
		if(check[i]==false) {
			dfs(i);
			idx++;
		}
	}
	
	cout<<idx<<'\n';
	for(int i=0; i<idx; i++) {
		for(auto& x : ans[i]) cout<<x+1<<' ';
		cout<<'\n';
	}
	
	return 0;
}
