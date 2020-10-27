/* reference: https://nicotina04.tistory.com/30 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii=pair<int,int>;
using ll=long long;

int main() {
	int N;
	cin>>N;

	vector<pii> a(N);
	for(int i=0; i<N; i++) cin>>a[i].first>>a[i].second;
	sort(a.begin(), a.end());

	int X=a[(N-1)/2].first;
	sort(a.begin(), a.end(), [](pii &l, pii&r) { return l.second < r.second; });
	int Y=a[(N-1)/2].second;
	
	ll ans=0;
	for(int i=0; i<N; i++) {
		ans += 1LL * abs(a[i].first-X) + abs(a[i].second-Y);
	}
	cout<<ans;

	return 0;
}
