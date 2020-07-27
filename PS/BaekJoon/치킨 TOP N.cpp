#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	vector<int> a(N);
	for(int i=0; i<N; i++) cin>>a[i];

	int K;
	cin>>K;
	
	K=N/K;
	for(int i=0; i<N; i+=K) sort(a.begin()+i, a.begin()+i+K);
	for(auto& x : a) cout<<x<<" ";
	
	return 0;
}
