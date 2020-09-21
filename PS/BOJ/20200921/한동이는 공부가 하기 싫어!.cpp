#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e3+1;

int a[MAX];
bool check[MAX];

int dfs(int x) {
	check[x]=true;
	int total=1;
	if(check[a[x]]==false) total+=dfs(a[x]);
	
	return total;
}

int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) cin>>a[i];

	int ans=-1, cnt=-1;	
	for(int i=1; i<=N; i++) {
		memset(check, false, sizeof(check));
		int visited=dfs(i);
		if(visited>cnt) {
			cnt=visited;
			ans=i;
		}
	}
	cout<<ans;
	
	return 0;
}
