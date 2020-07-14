#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;

		int a[N];
		for(int i=0; i<N; i++) cin>>a[i];

		vector<int> ans;
		for(int i=1; i<N-1; i++) {
			if(a[i-1]<a[i] && a[i+1]<a[i]) {
				ans={i, i+1, i+2};
				break;
			}
		}
		
		if(ans.size()) {
			cout<<"YES\n";
			for(auto x : ans) cout<<x<<" ";
		} else {
			cout<<"NO";
		}
		cout<<'\n';
	}

	return 0;
}
