#include <iostream>
#include <vector>

using namespace std;

const int MAX=1e3+1;

vector<int> a[MAX];
bool check[MAX];

void dfs(int x) {
	check[x]=true;
	for(auto& y : a[x]) {
		if(check[y]==false) dfs(y);
	}
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		for(int i=1; i<=N; i++) {
			a[i].clear();
			check[i]=false;	
		}
		
		for(int i=1; i<=N; i++) {
			int x;
			cin>>x;
			
			a[i].push_back(x);
		}
		
		int ans=0;
		for(int i=1; i<=N; i++) {
			if(check[i]==false) {
				dfs(i);
				ans++;
			}
		}
		
		cout<<ans<<'\n';
	}
	
	return 0;
}
