#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using PI=pair<int,int>;

bool cmp(const PI &l, const PI &r) {
	return l.second>r.second;
}

int main() {
	int n,k;
	cin>>n>>k;
	
	vector<PI> a(n);
	for(int i=0; i<n; i++) cin>>a[i].first>>a[i].second;
	sort(a.begin(), a.end(), cmp);
	
	multiset<int> s;
	for(int i=0; i<k; i++) {
		int t;
		cin>>t;
		
		s.insert(t);
	}
	
	long long ans=0;
	for(int i=0; i<n; i++) {
		auto it=s.lower_bound(a[i].first);
		if(it!=s.end()) {
			ans+=a[i].second;
			s.erase(it);
		}
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
3 2
1 65
5 23
2 99
10
2

OUTPUT:
164
*/
