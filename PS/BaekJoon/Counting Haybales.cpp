#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,Q;
	cin>>N>>Q;
	
	vector<int> a(N);
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a.begin(), a.end());
	
	while(Q--) {
		int x,y;
		cin>>x>>y;
		
		auto from=lower_bound(a.begin(), a.end(), x) - a.begin();
		auto to=upper_bound(a.begin(), a.end(), y) - a.begin();
		cout<<to-from<<'\n';
	}
	
	return 0;
}
