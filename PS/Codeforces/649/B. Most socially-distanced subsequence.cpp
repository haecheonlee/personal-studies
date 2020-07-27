/* reference: https://www.youtube.com/watch?v=JPdgvPcJWBc */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		vector<int> A(N);
		for(auto &a : A) cin>>a;
		
		vector<int> ans;
		for(int i=0; i<N; i++) {
			if(i!=0 && i!=N-1 && ((long long)A[i]-A[i-1])*((long long)A[i+1]-A[i])>0) continue;
			ans.push_back(A[i]);
		}
		
		cout<<ans.size()<<'\n';
		for(auto& x : ans) cout<<x<<" ";
		cout<<'\n';
	}
	
	return 0;
}
