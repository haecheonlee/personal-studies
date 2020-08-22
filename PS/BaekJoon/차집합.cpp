#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		int x;
		cin>>x;
		
		a.insert(x);
	}
	
	for(int i=0; i<M; i++) {
		int x;
		cin>>x;
		
		a.erase(x);
	}
	
	cout<<a.size()<<'\n';
	for(auto& x : a) cout<<x<<' ';
	
	return 0;
}
