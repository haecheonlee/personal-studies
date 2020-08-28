/* reference: https://sejinik.tistory.com/148 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll=long long;
using pi=pair<ll,ll>;

const ll LIMIT=1e10;

ll N,M,K;
vector<pi> a;

bool check(ll mid) {
	vector<ll> temp;
	for(auto& x : a) {
		if(x.first<=mid) temp.push_back(x.second);
		else break;
	}
	if(temp.size()<N) return false;
	
	sort(temp.rbegin(), temp.rend());
	
	ll total=0;
	for(int i=0; i<N; i++) total+=temp[i];
	
	return total>=M;
}

int main() {
	cin>>N>>M>>K;

	for(int i=0; i<K; i++) {
		ll pref,level;
		cin>>pref>>level;
		
		a.push_back(make_pair(level, pref));
	}
	sort(a.begin(), a.end());
	
	ll ans=LIMIT;
	ll L=1, R=LIMIT;
	while(L<=R) {
		ll mid=(L+R)/2;
		
		if(check(mid)) {
			R=mid-1;
			ans=min(ans,mid);
		} else {
			L=mid+1;
		}
	}
	
	if(ans==LIMIT) cout<<-1;
	else cout<<ans;

	return 0;
}
