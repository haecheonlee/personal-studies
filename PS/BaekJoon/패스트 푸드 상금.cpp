#include <iostream>
#include <vector>

using namespace std;

struct Prize {
	vector<int> stickers;
	int reward;
};

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,M;
		cin>>N>>M;

		vector<Prize> vec(N);
		for(int i=0; i<N; i++) {
			int K;
			cin>>K;
			
			vec[i].stickers.resize(K);
			for(int j=0; j<K; j++) cin>>vec[i].stickers[j];
			cin>>vec[i].reward;
		}

		int a[M+1];
		for(int i=1; i<=M; i++) cin>>a[i];

		int ans=0;
		for(int i=N-1; i>=0; i--) {
			int mn=1e6+1;
			for(auto x : vec[i].stickers) mn=min(mn,a[x]);
			for(auto x : vec[i].stickers) a[x]-=mn;
			ans+=(vec[i].reward*mn);
		}
		cout<<ans<<'\n';
	}

	return 0;
}
