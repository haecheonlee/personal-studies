/* reference: https://sosoeasy.tistory.com/m/120?category=891822 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll=long long;

bool check[10];

int main() {
	int N;
	cin>>N;

	string s[N];
	for(int i=0; i<N; i++) {
		cin>>s[i];
		check[s[i][0]-'A']=true;
		reverse(s[i].begin(), s[i].end());
	}

	vector<pair<ll,int>> a(10);
	for(int i=0; i<10; i++) a[i].second=i;

	for(int i=0; i<N; i++) {
		for(int j=0; j<(int)s[i].size(); j++) a[s[i][j]-'A'].first += pow(10, j);
	}

	sort(a.rbegin(), a.rend());

	vector<int> indexes;
	for(int i=9; i>=0; i--) indexes.push_back(i);

	ll ans=0;
	do {
		ll sum=0, is_passed=false, now=0;
		for(int i=0; i<(int)indexes.size(); i++) {
			if(check[a[now].second] && indexes[i]==0) { is_passed=true; break; }
			sum += indexes[i] * a[now++].first;
		}
		if(!is_passed) ans=max(ans, sum);
	} while(prev_permutation(indexes.begin(), indexes.end()));
	cout<<ans;

	return 0;
}
