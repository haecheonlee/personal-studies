/* reference: judge's solution */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	vector<int> a(N);
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a.begin(), a.end());
	
	long long ans=0;
	for(int i=0; i<N; i++) {
		int x=(9 * a[i] - 1)/10 + 1;
		auto it = lower_bound(a.begin(), a.begin()+i, x)-a.begin();
		ans+=(i-it);
	}
	cout<<ans;

	return 0;
}
