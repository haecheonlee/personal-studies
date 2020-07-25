#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

int main() {
	int N;
	cin>>N;
	
	vector<pi> a(N);
	for(int i=0; i<N; i++) cin>>a[i].second;
	for(int i=0; i<N; i++) cin>>a[i].first;
	sort(a.begin(), a.end());
	
	long long ans=0;
	for(int i=N-1; i>=0; i--) {
		ans+=(long long)(a[i].first*i)+a[i].second;
	}
	cout<<ans;
	
	return 0;
}
