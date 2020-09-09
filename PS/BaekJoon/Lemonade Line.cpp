#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	vector<int> a(N);
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a.rbegin(), a.rend());
	
	vector<int> ans;
	for(auto& x : a) {
		if(ans.size()<=x) ans.push_back(x);
	}
	cout<<ans.size();

	return 0;
}
