#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;

	vector<pi> a(N);
	for(int i=0; i<N; i++) 
		cin>>a[i].first>>a[i].second;
	sort(a.begin(), a.end());
	
	int ans=0;
	int R=-1e9;
	for(int i=0; i<N; i++) {
		if(R<=a[i].first) {
			ans+=abs(a[i].first-a[i].second);
			R=a[i].second;
		} else {
			if(R>=a[i].second) {
				continue;
			} else {
				ans+=abs(R-a[i].second);
				R=a[i].second;
			}
		}
	}
	cout<<ans;

	return 0;
}
