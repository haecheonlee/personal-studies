#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,Q;
	cin>>N>>Q;
	
	int a[N];
	int p[N+1];
	for(int i=0; i<N; i++) {
		cin>>a[i];
		
		p[i+1]=p[i]^a[i];
	}

	int ans=0;
	while(Q--) {
		int s,e;
		cin>>s>>e;
		
		ans^=(p[e]^p[s-1]);
	}
	cout<<ans;

	return 0;
}
