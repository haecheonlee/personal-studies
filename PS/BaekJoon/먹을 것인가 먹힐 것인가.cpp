#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	while(T--) {
		int N,M;
		cin>>N>>M;
		
		a.resize(N);
		for(int i=0; i<N; i++) cin>>a[i];
		sort(a.begin(),a.end());
		
		int ans=0;
		for(int i=0; i<M; i++) {
			int x;
			cin>>x;
			
			auto it=upper_bound(a.begin(), a.end(), x);
			ans+=N-(it-a.begin());
		}
		cout<<ans<<'\n';
	}

	return 0;
}
